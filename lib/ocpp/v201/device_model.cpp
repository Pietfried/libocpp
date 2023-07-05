// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2023 Pionix GmbH and Contributors to EVerest

#include <ocpp/v201/device_model.hpp>

#ifdef USE_EXTERNAL_DEVICE_MODEL_BACKEND
#include "device_model_storage_custom.hpp"
#endif

namespace ocpp {

namespace v201 {

bool DeviceModel::component_criteria_match(const Component& component,
                                           const std::vector<ComponentCriterionEnum>& component_criteria) {
    for (const auto& criteria : component_criteria) {
        const Variable variable = {conversions::component_criterion_enum_to_string(criteria)};
        // B08.FR.07
        // B08.FR.08
        // B08.FR.09
        // B08.FR.10
        if (!this->device_model.at(component).count(variable)) {
            return true;
        } else {
            const auto response =
                this->request_variable_attribute_value<bool>(component, variable, AttributeEnum::Actual);
            if (response.status == GetVariableStatusEnum::Accepted and response.value.value()) {
                return true;
            } else {
                return false;
            }
        }
    }
    return true;
}

DeviceModel::DeviceModel() {
#ifndef USE_EXTERNAL_DEVICE_MODEL_BACKEND
    this->storage = std::make_unique<DeviceModelStorageSqlite>("/tmp/device_model_ocpp201.db"); // FIXME(piet)
#else
    this->storage = std::make_unique<DeviceModelStorageCustom>();
#endif
    this->device_model = this->storage->get_device_model();
};

SetVariableStatusEnum DeviceModel::set_variable_attribute_value(const Component& component, const Variable& variable,
                                                                const AttributeEnum& attribute_enum,
                                                                const std::string& value) {
    if (this->device_model.find(component) != this->device_model.end()) {
        const auto _component = this->device_model[component];
        if (_component.find(variable) != _component.end()) {
            const auto attribute = this->storage->get_variable_attribute(component, variable, attribute_enum);
            if (attribute.has_value()) {
                if (attribute.value().mutability.has_value() and
                    attribute.value().mutability.value() != MutabilityEnum::ReadOnly) {
                    const auto success =
                        this->storage->set_variable_attribute_value(component, variable, attribute_enum, value);
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

std::optional<VariableMetaData> DeviceModel::get_variable_meta_data(const Component& component,
                                                                    const Variable& variable) {
    if (this->device_model.count(component) and this->device_model.at(component).count(variable)) {
        return this->device_model.at(component).at(variable);
    } else {
        return std::nullopt;
    }
}

std::vector<ReportData>
DeviceModel::get_report_data(const std::optional<ReportBaseEnum>& report_base,
                             const std::optional<std::vector<ComponentVariable>>& component_variables,
                             const std::optional<std::vector<ComponentCriterionEnum>>& component_criteria) {
    std::vector<ReportData> report_data_vec;

    for (auto const& [component, variable_map] : this->device_model) {
        if (!component_criteria.has_value() or component_criteria_match(component, component_criteria.value())) {
            for (auto const& [variable, variable_meta_data] : variable_map) {
                if (!component_variables.has_value() or
                    std::find_if(component_variables.value().begin(), component_variables.value().end(),
                                 [variable, component](ComponentVariable v) {
                                     return component == v.component and v.variable.has_value() and
                                            variable == v.variable.value();
                                 }) != component_variables.value().end()) {
                    ReportData report_data;
                    report_data.component = component;
                    report_data.variable = variable;

                    const auto variable_attributes = this->storage->get_variable_attributes(component, variable);
                    for (const auto& variable_attribute : variable_attributes) {
                        if (report_base == ReportBaseEnum::FullInventory or
                            variable_attribute.mutability == MutabilityEnum::ReadWrite or
                            variable_attribute.mutability == MutabilityEnum::WriteOnly) {
                            report_data.variableAttribute.push_back(variable_attribute);
                            report_data.variableCharacteristics = variable_map.at(variable).characteristics;
                        }
                    }
                    if (!report_data.variableAttribute.empty()) {
                        report_data_vec.push_back(report_data);
                    }
                }
            }
        }
    }
    return report_data_vec;
}

} // namespace v201
} // namespace ocpp
