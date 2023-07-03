// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2023 Pionix GmbH and Contributors to EVerest

#ifndef DEVICE_MODEL_STORAGE_SQLITE_HPP
#define DEVICE_MODEL_STORAGE_SQLITE_HPP

#include <filesystem>
#include <sqlite3.h>

#include <ocpp/v201/device_model_storage.hpp>

namespace ocpp {
namespace v201 {

/// \brief RAII wrapper class that handles finalization of sqlite3_stmt
class SQLiteStatement {
private:
    sqlite3_stmt* stmt;
public:
    SQLiteStatement(sqlite3* db, const std::string& query) : stmt(nullptr) {
        if (sqlite3_prepare_v2(db, query.c_str(), query.size(), &stmt, nullptr) != SQLITE_OK) {
            EVLOG_error << sqlite3_errmsg(db);
            EVLOG_AND_THROW(std::runtime_error("Could not prepare statement for database."));
        }
    }

    ~SQLiteStatement() {
        if (stmt != nullptr) {
            sqlite3_finalize(stmt);
        }
    }

    sqlite3_stmt* get() const {
        return stmt;
    }
};

class DeviceModelStorageSqlite : public DeviceModelStorage {

private:
    sqlite3* db;

public:
    /// \brief Opens SQLite connection at given \p db_path
    /// \param db_path  path to database
    DeviceModelStorageSqlite(const std::filesystem::path& db_path);

    std::map<Component, std::map<Variable, VariableMetaData>> get_device_model() override;

    std::optional<VariableAttribute> get_variable_attribute(const Component& component, const Variable& variable,
                                                            const AttributeEnum& attribute_enum) override;

    std::vector<VariableAttribute> get_variable_attributes(const Component& component, const Variable& variable,
                                                           const std::optional<AttributeEnum>& attribute_enum) override;

    bool set_variable_attribute_value(const Component& component, const Variable& variable, const AttributeEnum& attribute_enum,
                   const std::string& value) override;
};

} // namespace v201
} // namespace ocpp

#endif