// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2023 Pionix GmbH and Contributors to EVerest

#ifndef DEVICE_MODEL_HPP
#define DEVICE_MODEL_HPP

#include <ocpp/v201/device_model_storage.hpp>
#include <type_traits>

namespace ocpp {
namespace v201 {

namespace ControllerComponents {
const Component AlignedDataCtrlr{CiString<50>{"AlignedDataCtrlr"}};
const Component AuthCacheCtrlr{CiString<50>{"AuthCacheCtrlr"}};
const Component AuthCtrlr{CiString<50>{"AuthCtrlr"}};
const Component CHAdeMOCtrlr{CiString<50>{"CHAdeMOCtrlr"}};
const Component ClockCtrlr{CiString<50>{"ClockCtrlr"}};
const Component CustomizationCtrlr{CiString<50>{"CustomizationCtrlr"}};
const Component DeviceDataCtrlr{CiString<50>{"DeviceDataCtrlr"}};
const Component DisplayMessageCtrlr{CiString<50>{"DisplayMessageCtrlr"}};
const Component InternalCtrlr{CiString<50>{"InternalCtrlr"}};
const Component ISO15118Ctrlr{CiString<50>{"ISO15118Ctrlr"}};
const Component LocalAuthListCtrlr{CiString<50>{"LocalAuthListCtrlr"}};
const Component MonitoringCtrlr{CiString<50>{"MonitoringCtrlr"}};
const Component OCPPCommCtrlr{CiString<50>{"OCPPCommCtrlr"}};
const Component ReservationCtrlr{CiString<50>{"ReservationCtrlr"}};
const Component SampledDataCtrlr{CiString<50>{"SampledDataCtrlr"}};
const Component SecurityCtrlr{CiString<50>{"SecurityCtrlr"}};
const Component SmartChargingCtrlr{CiString<50>{"SmartChargingCtrlr"}};
const Component TariffCostCtrlr{CiString<50>{"TariffCostCtrlr"}};
const Component TxCtrlr{CiString<50>{"TxCtrlr"}};
} // namespace ControllerComponents

class DeviceModel {

private:
    std::map<Component, std::map<Variable, VariableMetaData>> device_model;

    std::unique_ptr<DeviceModelStorage> database;

public:
    DeviceModel();

    template <typename T>
    std::optional<T> get_value(const ComponentVariable& component_variable,
                               const AttributeEnum& attribute_enum = AttributeEnum::Actual) {
        return this->get_value<T>(component_variable.component, component_variable.variable, attribute_enum);
    };

    template <typename T>
    std::optional<T> get_value(const Component& component, const Variable& variable,
                               const AttributeEnum& attribute_enum) {
        if (this->device_model.find(component) != this->device_model.end()) {
            const auto _component = this->device_model[component];
            if (_component.find(variable) != _component.end()) {
                const auto _variable_meta_data = _component.at(variable);
                const auto value_str = this->database->get_value(component, variable, attribute_enum);
                if (_variable_meta_data.characteristics.dataType == DataEnum::string and
                    std::is_same<T, std::string>::value) {
                    return std::nullopt; // FIXME
                }
                if (_variable_meta_data.characteristics.dataType == DataEnum::integer and std::is_same<T, int>::value) {
                    std::cout << value_str.value() << std::endl;
                    return std::stoi(value_str.value());
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