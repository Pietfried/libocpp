// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2023 Pionix GmbH and Contributors to EVerest

#ifndef EXT_DEVICE_MODEL_STORAGE_CUSTOM_HPP
#define EXT_DEVICE_MODEL_STORAGE_CUSTOM_HPP

#include <ocpp/v201/device_model_storage.hpp>

namespace ocpp::v201 {

class DeviceModelStorageCustom : public DeviceModelStorage {
public:
    std::map<Component, std::map<Variable, VariableMetaData>> get_device_model() final;

    std::optional<VariableAttribute> get_variable_attribute(const Component& component, const Variable& variable,
                                                            const AttributeEnum& attribute_enum) final;

    std::vector<VariableAttribute> get_variable_attributes(const Component& component, const Variable& variable,
                                                           const std::optional<AttributeEnum>& attribute_enum) final;

    bool set_variable_attribute_value(const Component& component, const Variable& variable,
                                      const AttributeEnum& attribute_enum, const std::string& value) final;
};

} // namespace ocpp::v201

#endif // EXT_DEVICE_MODEL_STORAGE_CUSTOM_HPP
