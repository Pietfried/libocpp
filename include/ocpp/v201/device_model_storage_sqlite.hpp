// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2023 Pionix GmbH and Contributors to EVerest

#ifndef DEVICE_MODEL_STORAGE_SQLITE_HPP
#define DEVICE_MODEL_STORAGE_SQLITE_HPP

#include <filesystem>
#include <sqlite3.h>

#include <ocpp/v201/device_model_storage.hpp>

namespace ocpp {
namespace v201 {

class DeviceModelStorageSqlite : public DeviceModelStorage {

private:
    sqlite3* db;

public:
    DeviceModelStorageSqlite(const std::filesystem::path& db_path);

    std::map<Component, std::map<Variable, VariableMetaData>> get_device_model() override;

    std::optional<VariableAttribute> get_variable_attribute(const Component& component, const Variable& variable,
                                                            const AttributeEnum& attribute_enum) override;

    std::optional<std::string> get_value(const Component& component, const Variable& variable,
                                         const AttributeEnum& attribute_enum) override;

    bool set_value(const Component& component, const Variable& variable, const AttributeEnum& attribute_enum,
                   const std::string& value) override;
};

} // namespace v201
} // namespace ocpp

#endif