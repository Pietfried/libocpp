// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2023 Pionix GmbH and Contributors to EVerest

#include <ocpp/v201/device_model_storage_sqlite.hpp>

namespace ocpp {

namespace v201 {

DeviceModelStorageSqlite::DeviceModelStorageSqlite(const std::filesystem::path& db_path) : db_path(db_path) {
    if (sqlite3_open(db_path.c_str(), &this->db) != SQLITE_OK) {
        EVLOG_info << "Error opening database: " << sqlite3_errmsg(db);
        throw std::runtime_error("Could not open database at provided path.");
    } else {
        EVLOG_info << "Established connection to database successfully!";
    }
}

std::map<Component, std::map<Variable, VariableMetaData>> DatabaseSqlite::get_device_model() {
    std::map<Component, std::map<Variable, VariableMetaData>> device_model;

    std::string select_query = "SELECT c.COMPONENT_NAME, c.EVSE_ID, c.INSTANCE_ID, v.NAME, v.INSTANCE_ID, vc.DATATYPE, "
                               "vc.SUPPORTS_MONITORING, vc.UNIT, vc.MIN_LIMIT, vc.MAX_LIMIT, vc.VALUES_LIST "
                               "FROM COMPONENT c "
                               "JOIN VARIABLE v ON c.ID = v.COMPONENT_ID "
                               "JOIN VARIABLE_CHARACTERISTICS vc ON v.VARIABLE_CHARACTERISTICS_ID = vc.ID";

    sqlite3_stmt* select_stmt;
    auto rc = sqlite3_prepare_v2(db, select_query.c_str(), -1, &select_stmt, nullptr);

    if (rc != SQLITE_OK) {
        // Handle query preparation error
        sqlite3_close(db);
        return device_model;
    }

    // Execute the select query
    while (sqlite3_step(select_stmt) == SQLITE_ROW) {
        Component component;
        component.name = reinterpret_cast<const char*>(sqlite3_column_text(select_stmt, 0));

        if (sqlite3_column_type(select_stmt, 1) != SQLITE_NULL) {
            auto evse_id = sqlite3_column_int(select_stmt, 1);
            EVSE evse;
            evse.id = evse_id;
            component.evse = evse;
        }

        if (sqlite3_column_type(select_stmt, 2) != SQLITE_NULL) {
            component.instance = reinterpret_cast<const char*>(sqlite3_column_text(select_stmt, 2));
        }

        Variable variable;
        variable.name = reinterpret_cast<const char*>(sqlite3_column_text(select_stmt, 3));

        if (sqlite3_column_type(select_stmt, 4) != SQLITE_NULL) {
            variable.instance = reinterpret_cast<const char*>(sqlite3_column_text(select_stmt, 4));
        }

        VariableCharacteristics characteristics;
        characteristics.dataType =
            string_to_data_enum(reinterpret_cast<const char*>(sqlite3_column_text(select_stmt, 5)));
        characteristics.supportsMonitoring = sqlite3_column_int(select_stmt, 6) != 0;

        if (sqlite3_column_type(select_stmt, 7) != SQLITE_NULL) {
            characteristics.unit = reinterpret_cast<const char*>(sqlite3_column_text(select_stmt, 7));
        }

        if (sqlite3_column_type(select_stmt, 8) != SQLITE_NULL) {
            characteristics.minLimit = sqlite3_column_double(select_stmt, 8);
        }

        if (sqlite3_column_type(select_stmt, 9) != SQLITE_NULL) {
            characteristics.maxLimit = sqlite3_column_double(select_stmt, 9);
        }

        if (sqlite3_column_type(select_stmt, 10) != SQLITE_NULL) {
            characteristics.valuesList = reinterpret_cast<const char*>(sqlite3_column_text(select_stmt, 10));
        }

        VariableMetaData meta_data;
        meta_data.characteristics = characteristics;

        device_model[component][variable] = meta_data;
    }

    sqlite3_finalize(select_stmt);

    EVLOG_info << "Successfully retrieved Device Model from DeviceModelStorage";
    return device_model;
}

std::optional<VariableAttribute> DatabaseSqlite::get_variable_attribute(const Component& component,
                                                                        const Variable& variable,
                                                                        const AttributeEnum& attribute_enum) {

    std::optional<VariableAttribute> result;

    std::string select_query = "SELECT va.VALUE, va.MUTABILITY, va.PERSISTENT, va.CONSTANT "
                               "FROM VARIABLE_ATTRIBUTE va "
                               "JOIN VARIABLE v ON va.VARIABLE_ID = v.ID "
                               "JOIN COMPONENT c ON v.COMPONENT_ID = c.ID "
                               "WHERE c.COMPONENT_NAME = ? AND v.NAME = ? AND va.ATTRIBUTE_TYPE_ID = ?";

    sqlite3_stmt* select_stmt;
    auto rc = sqlite3_prepare_v2(db, select_query.c_str(), -1, &select_stmt, nullptr);

    if (rc != SQLITE_OK) {
        EVLOG_info << sqlite3_errmsg(db);
        sqlite3_close(db);
        return result;
    }

    // Bind the parameters to the prepared statement
    sqlite3_bind_text(select_stmt, 1, component.name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(select_stmt, 2, variable.name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(select_stmt, 3, static_cast<int>(1));

    // Execute the select query
    if (sqlite3_step(select_stmt) == SQLITE_ROW) {
        VariableAttribute attribute;

        // Retrieve column values and assign them to the corresponding members of the attribute object
        if (sqlite3_column_type(select_stmt, 0) != SQLITE_NULL) {
            attribute.value = reinterpret_cast<const char*>(sqlite3_column_text(select_stmt, 0));
        }
        attribute.mutability = MutabilityEnum::ReadWrite;
        attribute.persistent = static_cast<bool>(sqlite3_column_int(select_stmt, 2));
        attribute.constant = static_cast<bool>(sqlite3_column_int(select_stmt, 3));

        result = attribute;
    }

    sqlite3_finalize(select_stmt);
    return result;
}

std::optional<std::string> DatabaseSqlite::get_value(const Component& component, const Variable& variable,
                                                     const AttributeEnum& attribute_enum) {
    const auto attribute = this->get_variable_attribute(component, variable, attribute_enum);
    if (attribute.has_value()) {
        return attribute.value().value;
    }
    return std::nullopt;
}

bool DatabaseSqlite::set_value(const Component& component, const Variable& variable,
                               const AttributeEnum& attribute_enum, const std::string& value) {
    const auto select_component_id_query = "SELECT ID FROM COMPONENT WHERE COMPONENT_NAME = ?";
    const auto select_variable_id_query = "SELECT ID FROM VARIABLE WHERE NAME = ?";
    const auto select_attribute_type_id_query = "SELECT ID FROM VARIABLE_ATTRIBUTE_TYPE WHERE ATTRIBUTE_TYPE = ?";
    const auto insert_query = "UPDATE VARIABLE_ATTRIBUTE SET VALUE=? WHERE VARIABLE_ID = ? AND ATTRIBUTE_TYPE_ID = ?";

    sqlite3_stmt* select_component_id_stmt;
    sqlite3_stmt* select_variable_id_stmt;
    sqlite3_stmt* select_attribute_type_id_stmt;
    sqlite3_stmt* insert_stmt;

    // Prepare the select queries
    auto rc = sqlite3_prepare_v2(db, select_component_id_query, -1, &select_component_id_stmt, nullptr);
    if (rc != SQLITE_OK) {
        // Handle query preparation error
        return false;
    }

    rc = sqlite3_prepare_v2(db, select_variable_id_query, -1, &select_variable_id_stmt, nullptr);
    if (rc != SQLITE_OK) {
        // Handle query preparation error
        sqlite3_finalize(select_component_id_stmt);
        return false;
    }

    rc = sqlite3_prepare_v2(db, select_attribute_type_id_query, -1, &select_attribute_type_id_stmt, nullptr);
    if (rc != SQLITE_OK) {
        // Handle query preparation error
        sqlite3_finalize(select_component_id_stmt);
        sqlite3_finalize(select_variable_id_stmt);
        return false;
    }

    // Bind values to the select queries
    sqlite3_bind_text(select_component_id_stmt, 1, component.name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(select_variable_id_stmt, 1, variable.name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(select_attribute_type_id_stmt, 1, "Actual", -1, SQLITE_STATIC);

    // Execute the select queries
    auto component_id = -1;
    auto variable_id = -1;
    auto attribute_type_id = -1;

    rc = sqlite3_step(select_component_id_stmt);
    if (rc == SQLITE_ROW) {
        // Retrieve the component ID
        component_id = sqlite3_column_int(select_component_id_stmt, 0);
    }

    rc = sqlite3_step(select_variable_id_stmt);
    if (rc == SQLITE_ROW) {
        // Retrieve the variable ID
        variable_id = sqlite3_column_int(select_variable_id_stmt, 0);
    }

    rc = sqlite3_step(select_attribute_type_id_stmt);
    if (rc == SQLITE_ROW) {
        // Retrieve the attribute type ID
        attribute_type_id = sqlite3_column_int(select_attribute_type_id_stmt, 0);
    }

    sqlite3_finalize(select_component_id_stmt);
    sqlite3_finalize(select_variable_id_stmt);
    sqlite3_finalize(select_attribute_type_id_stmt);

    // Prepare the insert query
    rc = sqlite3_prepare_v2(db, insert_query, -1, &insert_stmt, nullptr);
    if (rc != SQLITE_OK) {
        // Handle query preparation error
        return rc;
    }

    // Bind values to the insert query
    sqlite3_bind_text(insert_stmt, 1, value.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(insert_stmt, 2, variable_id);
    sqlite3_bind_int(insert_stmt, 3, attribute_type_id);

    // Execute the insert query
    rc = sqlite3_step(insert_stmt);
    if (rc != SQLITE_DONE) {
        // Handle query execution error
        sqlite3_finalize(insert_stmt);
        return rc;
    }

    sqlite3_finalize(insert_stmt);

    return true;
}

} // namespace v201
} // namespace ocpp
