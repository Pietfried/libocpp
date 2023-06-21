// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2023 Pionix GmbH and Contributors to EVerest

#include <ocpp/v201/device_model.hpp>

namespace ocpp {

namespace v201 {

DeviceModel::DeviceModel() {
    this->device_model_storage = std::make_unique<DatabaseSqlite>();
    this->device_model = this->device_model_storage->get_device_model();
};

SetVariableStatusEnum DeviceModel::set_value(const Component& component, const Variable& variable,
                                             const AttributeEnum& attribute_enum, const std::string& value) {
    if (this->device_model.find(component) != this->device_model.end()) {
        const auto _component = this->device_model[component];

        if (_component.find(variable) != _component.end()) {
            const auto attribute =
                this->device_model_storage->get_variable_attribute(component, variable, attribute_enum);
            if (attribute.has_value()) {
                if (attribute.value().mutability.has_value() and
                    attribute.value().mutability.value() != MutabilityEnum::ReadOnly) {
                    const auto success =
                        this->device_model_storage->set_value(component, variable, attribute_enum, value);
                    return success ? SetVariableStatusEnum::Accepted : SetVariableStatusEnum::Rejected;
                } else {
                    return SetVariableStatusEnum::Rejected;
                }
            } else {
                return SetVariableStatusEnum::NotSupportedAttributeType;
            }
        } else {
            return SetVariableStatusEnum::UnknownVariable;
        }
    } else {
        return SetVariableStatusEnum::UnknownComponent;
    }
};

} // namespace v201
} // namespace ocpp