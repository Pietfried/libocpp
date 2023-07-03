// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2023 Pionix GmbH and Contributors to EVerest

#include <everest/logging.hpp>
#include <ocpp/v201/device_model_storage_sqlite.hpp>

namespace ocpp {

namespace v201 {

DeviceModelStorageSqlite::DeviceModelStorageSqlite(const std::filesystem::path& db_path) {
    if (sqlite3_open(db_path.c_str(), &this->db) != SQLITE_OK) {
        EVLOG_error << "Could not open database at provided path: " << db_path;
        EVLOG_AND_THROW(std::runtime_error("Could not open device model database at provided path."));
    } else {
        EVLOG_info << "Established connection to device model database successfully: " << db_path;
    }
}

std::map<Component, std::map<Variable, VariableMetaData>> DeviceModelStorageSqlite::get_device_model() {
    std::map<Component, std::map<Variable, VariableMetaData>> device_model;

    std::string select_query = "SELECT c.NAME, c.EVSE_ID, c.INSTANCE, v.NAME, v.INSTANCE, vc.DATATYPE_ID, "
                               "vc.SUPPORTS_MONITORING, vc.UNIT, vc.MIN_LIMIT, vc.MAX_LIMIT, vc.VALUES_LIST "
                               "FROM COMPONENT c "
                               "JOIN VARIABLE v ON c.ID = v.COMPONENT_ID "
                               "JOIN VARIABLE_CHARACTERISTICS vc ON v.VARIABLE_CHARACTERISTICS_ID = vc.ID";

    SQLiteStatement select_stmt(this->db, select_query);

    // Execute the select query
    while (sqlite3_step(select_stmt.get()) == SQLITE_ROW) {
        Component component;
        component.name = reinterpret_cast<const char*>(sqlite3_column_text(select_stmt.get(), 0));

        if (sqlite3_column_type(select_stmt.get(), 1) != SQLITE_NULL) {
            auto evse_id = sqlite3_column_int(select_stmt.get(), 1);
            EVSE evse;
            evse.id = evse_id;
            component.evse = evse;
        }

        if (sqlite3_column_type(select_stmt.get(), 2) != SQLITE_NULL) {
            component.instance = reinterpret_cast<const char*>(sqlite3_column_text(select_stmt.get(), 2));
        }

        Variable variable;
        variable.name = reinterpret_cast<const char*>(sqlite3_column_text(select_stmt.get(), 3));

        if (sqlite3_column_type(select_stmt.get(), 4) != SQLITE_NULL) {
            variable.instance = reinterpret_cast<const char*>(sqlite3_column_text(select_stmt.get(), 4));
        }

        VariableCharacteristics characteristics;
        characteristics.dataType = static_cast<DataEnum>(sqlite3_column_int(select_stmt.get(), 5));
        characteristics.supportsMonitoring = sqlite3_column_int(select_stmt.get(), 6) != 0;

        if (sqlite3_column_type(select_stmt.get(), 7) != SQLITE_NULL) {
            characteristics.unit = reinterpret_cast<const char*>(sqlite3_column_text(select_stmt.get(), 7));
        }

        if (sqlite3_column_type(select_stmt.get(), 8) != SQLITE_NULL) {
            characteristics.minLimit = sqlite3_column_double(select_stmt.get(), 8);
        }

        if (sqlite3_column_type(select_stmt.get(), 9) != SQLITE_NULL) {
            characteristics.maxLimit = sqlite3_column_double(select_stmt.get(), 9);
        }

        if (sqlite3_column_type(select_stmt.get(), 10) != SQLITE_NULL) {
            characteristics.valuesList = reinterpret_cast<const char*>(sqlite3_column_text(select_stmt.get(), 10));
        }

        VariableMetaData meta_data;
        meta_data.characteristics = characteristics;

        device_model[component][variable] = meta_data;
    }

    EVLOG_info << "Successfully retrieved Device Model from DeviceModelStorage";
    return device_model;
}

std::optional<VariableAttribute> DeviceModelStorageSqlite::get_variable_attribute(const Component& component,
                                                                                  const Variable& variable,
                                                                                  const AttributeEnum& attribute_enum) {
    const auto attributes = this->get_variable_attributes(component, variable, attribute_enum);
    if (!attributes.empty()) {
        return attributes.at(0);
    } else {
        return std::nullopt;
    }
}

std::vector<VariableAttribute>
DeviceModelStorageSqlite::get_variable_attributes(const Component& component, const Variable& variable,
                                                  const std::optional<AttributeEnum>& attribute_enum) {
    std::vector<VariableAttribute> attributes;

    std::string select_query = "SELECT va.VALUE, va.MUTABILITY_ID, va.PERSISTENT, va.CONSTANT, va.TYPE_ID "
                               "FROM VARIABLE_ATTRIBUTE va "
                               "JOIN VARIABLE v ON va.VARIABLE_ID = v.ID "
                               "JOIN COMPONENT c ON v.COMPONENT_ID = c.ID "
                               "WHERE c.NAME = @component_name AND v.NAME = @variable_name";

    if (attribute_enum.has_value()) {
        std::stringstream ss;
        ss << select_query << "  AND va.TYPE_ID = " << static_cast<int>(attribute_enum.value());
        select_query = ss.str();
    }

    SQLiteStatement select_stmt(this->db, select_query);


    const auto component_name = component.name.get();
    const auto variable_name = variable.name.get();

    // Bind the parameters to the prepared statement
    sqlite3_bind_text(select_stmt.get(), 1, component_name.c_str(), component_name.length(), NULL);
    sqlite3_bind_text(select_stmt.get(), 2, variable_name.c_str(), variable_name.length(), NULL);

    // Execute the select query
    while (sqlite3_step(select_stmt.get()) == SQLITE_ROW) {
        VariableAttribute attribute;

        // Retrieve column values and assign them to the corresponding members of the attribute object
        if (sqlite3_column_type(select_stmt.get(), 0) != SQLITE_NULL) {
            attribute.value = reinterpret_cast<const char*>(sqlite3_column_text(select_stmt.get(), 0));
        }
        attribute.mutability = static_cast<MutabilityEnum>(sqlite3_column_int(select_stmt.get(), 1));
        attribute.persistent = static_cast<bool>(sqlite3_column_int(select_stmt.get(), 2));
        attribute.constant = static_cast<bool>(sqlite3_column_int(select_stmt.get(), 3));
        attribute.type = static_cast<AttributeEnum>(sqlite3_column_int(select_stmt.get(), 4));
        attributes.push_back(attribute);
    }

    return attributes;
}

bool DeviceModelStorageSqlite::set_variable_attribute_value(const Component& component, const Variable& variable,
                                                            const AttributeEnum& attribute_enum,
                                                            const std::string& value) {
    std::string select_component_id_query = "SELECT ID FROM COMPONENT WHERE NAME = ?";
    std::string select_variable_id_query = "SELECT ID FROM VARIABLE WHERE NAME = ?";
    std::string select_attribute_type_id_query = "SELECT ID FROM VARIABLE_ATTRIBUTE_TYPE WHERE ID = ?";
    std::string insert_query = "UPDATE VARIABLE_ATTRIBUTE SET VALUE=? WHERE VARIABLE_ID = ? AND TYPE_ID = ?";

    SQLiteStatement select_component_id_stmt(this->db, select_component_id_query);
    SQLiteStatement select_variable_id_stmt(this->db, select_variable_id_query);
    SQLiteStatement select_attribute_type_id_stmt(this->db, select_attribute_type_id_query);
    SQLiteStatement insert_stmt(this->db, insert_query);

    const auto component_name = component.name.get();
    const auto variable_name = variable.name.get();

    // Bind values to the select queries
    sqlite3_bind_text(select_component_id_stmt.get(), 1, component_name.c_str(), component_name.length(), NULL);
    sqlite3_bind_text(select_variable_id_stmt.get(), 1, variable_name.c_str(), variable_name.length(), NULL);
    sqlite3_bind_int(select_attribute_type_id_stmt.get(), 1, static_cast<int>(attribute_enum));

    // Execute the select queries
    auto component_id = -1;
    auto variable_id = -1;
    auto attribute_type_id = -1;

    auto rc = sqlite3_step(select_component_id_stmt.get());
    if (rc == SQLITE_ROW) {
        component_id = sqlite3_column_int(select_component_id_stmt.get(), 0);
    } else {
        return false;
    }

    rc = sqlite3_step(select_variable_id_stmt.get());
    if (rc == SQLITE_ROW) {
        variable_id = sqlite3_column_int(select_variable_id_stmt.get(), 0);
    } else {
        return false;
    }

    rc = sqlite3_step(select_attribute_type_id_stmt.get());
    if (rc == SQLITE_ROW) {
        attribute_type_id = sqlite3_column_int(select_attribute_type_id_stmt.get(), 0);
    } else {
        return false;
    }

    // Bind values to the insert query
    sqlite3_bind_text(insert_stmt.get(), 1, value.c_str(), value.length(), NULL);
    sqlite3_bind_int(insert_stmt.get(), 2, variable_id);
    sqlite3_bind_int(insert_stmt.get(), 3, attribute_type_id);

    // Execute the insert query
    rc = sqlite3_step(insert_stmt.get());
    if (rc != SQLITE_DONE) {
        EVLOG_error << sqlite3_errmsg(this->db);
        return false;
    }

    return true;
}

} // namespace v201
} // namespace ocpp
