// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2023 Pionix GmbH and Contributors to EVerest

#ifndef OCPP_V201_DEVICE_MODEL_STORAGE_HPP
#define OCPP_V201_DEVICE_MODEL_STORAGE_HPP

#include <filesystem>
#include <map>
#include <memory>
#include <optional>
#include <ocpp/v201/ocpp_types.hpp>

namespace ocpp {
namespace v201 {

struct VariableMetaData {
    VariableCharacteristics characteristics;
    std::vector<VariableMonitoring> monitors;
};

class DeviceModelStorage {

public:
    virtual ~DeviceModelStorage(){};

    virtual std::map<Component, std::map<Variable, VariableMetaData>> get_device_model() = 0;

    virtual std::optional<VariableAttribute> get_variable_attribute(const Component& component,
                                                                    const Variable& variable,
                                                                    const AttributeEnum& attribute_enum) = 0;

    virtual std::optional<std::string> get_value(const Component& component, const Variable& variable,
                                                 const AttributeEnum& attribute_enum) = 0;

    virtual bool set_value(const Component& component, const Variable& variable, const AttributeEnum& attribute_enum,
                           const std::string& value) = 0;
};

} // namespace v201
} // namespace ocpp

#endif // OCPP_V201_DEVICE_MODEL_STORAGE_HPP