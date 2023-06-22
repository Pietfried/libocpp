// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2023 Pionix GmbH and Contributors to EVerest

#ifndef DEVICE_MODEL_HPP
#define DEVICE_MODEL_HPP

#include <ocpp/v201/device_model_storage.hpp>
#include <ocpp/v201/device_model_storage_sqlite.hpp>
#include <type_traits>

namespace ocpp {
namespace v201 {

class DeviceModel {

private:
    std::map<Component, std::map<Variable, VariableMetaData>> device_model;
    std::unique_ptr<DeviceModelStorage> device_model_storage;

public:
    DeviceModel();

    template <typename T>
    T get_value(const ComponentVariable& component_variable,
                const AttributeEnum& attribute_enum = AttributeEnum::Actual) {
        return this->get_value<T>(component_variable.component, component_variable.variable.value(), attribute_enum)
            .value();
    };

    template <typename T>
    std::optional<T> get_optional_value(const ComponentVariable& component_variable,
                                        const AttributeEnum& attribute_enum = AttributeEnum::Actual) {
        return this->get_value<T>(component_variable.component, component_variable.variable.value(), attribute_enum);
    };

    template <typename T>
    std::optional<T> get_value(const Component& component, const Variable& variable,
                               const AttributeEnum& attribute_enum) {
        if (this->device_model.find(component) != this->device_model.end()) {
            const auto _component = this->device_model[component];
            if (_component.find(variable) != _component.end()) {
                const auto _variable_meta_data = _component.at(variable);
                const auto value_opt = this->device_model_storage->get_value(component, variable, attribute_enum);
                if (value_opt.has_value()) {

                    if constexpr (std::is_same<T, std::string>::value) {
                        if (_variable_meta_data.characteristics.dataType == DataEnum::string) {
                            return value_opt.value();
                        } else {
                            return std::nullopt;
                            // throw exception
                        }
                    } else if constexpr (std::is_same<T, int>::value) {
                        if (_variable_meta_data.characteristics.dataType == DataEnum::integer) {
                            return std::stoi(value_opt.value());
                        } else {
                            return std::nullopt;
                        }
                    } else {
                        /** continue here **/
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }

            } else {
                return std::nullopt;
            }
        } else {
            return std::nullopt;
        }
    }

    SetVariableStatusEnum set_value(const Component& component, const Variable& variable,
                                    const AttributeEnum& attribute_enum, const std::string& value);

    void on_variable_changed(const Component& component, const Variable& variable, const AttributeEnum& attribute_enum,
                             const std::string& value);

    void /*add proper return type*/ get_report_data(/*add proper args...*/);
};

} // namespace v201
} // namespace ocpp

#endif