// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2023 Pionix GmbH and Contributors to EVerest

#include "device_model_storage_custom.hpp"

namespace ocpp::v201 {

std::map<Component, std::map<Variable, VariableMetaData>> DeviceModelStorageCustom::get_device_model() {
    return {};
}

std::optional<VariableAttribute> DeviceModelStorageCustom::get_variable_attribute(const Component& component,
                                                                                  const Variable& variable,
                                                                                  const AttributeEnum& attribute_enum) {
    return {};
}

std::vector<VariableAttribute>
DeviceModelStorageCustom::get_variable_attributes(const Component& component, const Variable& variable,
                                                  const std::optional<AttributeEnum>& attribute_enum) {
    return {};
}

bool DeviceModelStorageCustom::set_variable_attribute_value(const Component& component, const Variable& variable,
                                                            const AttributeEnum& attribute_enum,
                                                            const std::string& value) {
    return true;
}

} // namespace ocpp::v201
