// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2023 Pionix GmbH and Contributors to EVerest

#ifndef DEVICE_MODEL_HPP
#define DEVICE_MODEL_HPP

#include <type_traits>

#include <everest/logging.hpp>

#include <ocpp/v201/device_model_storage.hpp>
#include <ocpp/v201/device_model_storage_sqlite.hpp>

namespace ocpp {
namespace v201 {

// represents all variables with a role standardized in OCPP2.0.1 for easy access
namespace ControllerComponentVariables {

const ComponentVariable InternalCtrlrEnabled = {{"InternalCtrlr"}, std::nullopt, std::optional<Variable>({"Enabled"})};
const ComponentVariable ChargePointId = {{"InternalCtrlr"}, std::nullopt, std::optional<Variable>({"ChargePointId"})};
const ComponentVariable CentralSystemURI = {
    {"InternalCtrlr"}, std::nullopt, std::optional<Variable>({"CentralSystemURI"})};
const ComponentVariable ChargeBoxSerialNumber = {
    {"InternalCtrlr"}, std::nullopt, std::optional<Variable>({"ChargeBoxSerialNumber"})};
const ComponentVariable ChargePointModel = {
    {"InternalCtrlr"}, std::nullopt, std::optional<Variable>({"ChargePointModel"})};
const ComponentVariable ChargePointSerialNumber = {
    {"InternalCtrlr"}, std::nullopt, std::optional<Variable>({"ChargePointSerialNumber"})};
const ComponentVariable ChargePointVendor = {
    {"InternalCtrlr"}, std::nullopt, std::optional<Variable>({"ChargePointVendor"})};
const ComponentVariable FirmwareVersion = {
    {"InternalCtrlr"}, std::nullopt, std::optional<Variable>({"FirmwareVersion"})};
const ComponentVariable ICCID = {{"InternalCtrlr"}, std::nullopt, std::optional<Variable>({"ICCID"})};
const ComponentVariable IMSI = {{"InternalCtrlr"}, std::nullopt, std::optional<Variable>({"IMSI"})};
const ComponentVariable MeterSerialNumber = {
    {"InternalCtrlr"}, std::nullopt, std::optional<Variable>({"MeterSerialNumber"})};
const ComponentVariable MeterType = {{"InternalCtrlr"}, std::nullopt, std::optional<Variable>({"MeterType"})};
const ComponentVariable SupportedCiphers12 = {
    {"InternalCtrlr"}, std::nullopt, std::optional<Variable>({"SupportedCiphers12"})};
const ComponentVariable SupportedCiphers13 = {
    {"InternalCtrlr"}, std::nullopt, std::optional<Variable>({"SupportedCiphers13"})};
const ComponentVariable WebsocketReconnectInterval = {
    {"InternalCtrlr"}, std::nullopt, std::optional<Variable>({"WebsocketReconnectInterval"})};
const ComponentVariable AuthorizeConnectorZeroOnConnectorOne = {
    {"InternalCtrlr"}, std::nullopt, std::optional<Variable>({"AuthorizeConnectorZeroOnConnectorOne"})};
const ComponentVariable LogMessages = {{"InternalCtrlr"}, std::nullopt, std::optional<Variable>({"LogMessages"})};
const ComponentVariable LogMessagesFormat = {
    {"InternalCtrlr"}, std::nullopt, std::optional<Variable>({"LogMessagesFormat"})};
const ComponentVariable SupportedChargingProfilePurposeTypes = {
    {"InternalCtrlr"}, std::nullopt, std::optional<Variable>({"SupportedChargingProfilePurposeTypes"})};
const ComponentVariable MaxCompositeScheduleDuration = {
    {"InternalCtrlr"}, std::nullopt, std::optional<Variable>({"MaxCompositeScheduleDuration"})};
const ComponentVariable NumberOfConnectors = {
    {"InternalCtrlr"}, std::nullopt, std::optional<Variable>({"NumberOfConnectors"})};
const ComponentVariable UseSslDefaultVerifyPaths = {
    {"InternalCtrlr"}, std::nullopt, std::optional<Variable>({"UseSslDefaultVerifyPaths"})};
const ComponentVariable OcspRequestInterval = {
    {"InternalCtrlr"}, std::nullopt, std::optional<Variable>({"OcspRequestInterval"})};
const ComponentVariable WebsocketPingPayload = {
    {"InternalCtrlr"}, std::nullopt, std::optional<Variable>({"WebsocketPingPayload"})};
const ComponentVariable AlignedDataCtrlrEnabled = {
    {"AlignedDataCtrlr"}, std::nullopt, std::optional<Variable>({"Enabled"})};
const ComponentVariable AlignedDataCtrlrAvailable = {
    {"AlignedDataCtrlr"}, std::nullopt, std::optional<Variable>({"Available"})};
const ComponentVariable AlignedDataInterval = {
    {"AlignedDataCtrlr"}, std::nullopt, std::optional<Variable>({"AlignedDataInterval"})};
const ComponentVariable AlignedDataMeasurands = {
    {"AlignedDataCtrlr"}, std::nullopt, std::optional<Variable>({"AlignedDataMeasurands"})};
const ComponentVariable AlignedDataSendDuringIdle = {
    {"AlignedDataCtrlr"}, std::nullopt, std::optional<Variable>({"AlignedDataSendDuringIdle"})};
const ComponentVariable AlignedDataSignReadings = {
    {"AlignedDataCtrlr"}, std::nullopt, std::optional<Variable>({"AlignedDataSignReadings"})};
const ComponentVariable AlignedDataTxEndedInterval = {
    {"AlignedDataCtrlr"}, std::nullopt, std::optional<Variable>({"AlignedDataTxEndedInterval"})};
const ComponentVariable AlignedDataTxEndedMeasurands = {
    {"AlignedDataCtrlr"}, std::nullopt, std::optional<Variable>({"AlignedDataTxEndedMeasurands"})};
const ComponentVariable AuthCacheCtrlrAvailable = {
    {"AuthCacheCtrlr"}, std::nullopt, std::optional<Variable>({"Available"})};
const ComponentVariable AuthCacheCtrlrEnabled = {
    {"AuthCacheCtrlr"}, std::nullopt, std::optional<Variable>({"Enabled"})};
const ComponentVariable AuthCacheLifeTime = {
    {"AuthCacheCtrlr"}, std::nullopt, std::optional<Variable>({"AuthCacheLifeTime"})};
const ComponentVariable AuthCachePolicy = {
    {"AuthCacheCtrlr"}, std::nullopt, std::optional<Variable>({"AuthCachePolicy"})};
const ComponentVariable AuthCacheStorage = {
    {"AuthCacheCtrlr"}, std::nullopt, std::optional<Variable>({"AuthCacheStorage"})};
const ComponentVariable AuthCtrlrEnabled = {{"AuthCtrlr"}, std::nullopt, std::optional<Variable>({"Enabled"})};
const ComponentVariable AdditionalInfoItemsPerMessage = {
    {"AuthCtrlr"}, std::nullopt, std::optional<Variable>({"AdditionalInfoItemsPerMessage"})};
const ComponentVariable AuthorizeRemoteStart = {
    {"AuthCtrlr"}, std::nullopt, std::optional<Variable>({"AuthorizeRemoteStart"})};
const ComponentVariable LocalAuthorizeOffline = {
    {"AuthCtrlr"}, std::nullopt, std::optional<Variable>({"LocalAuthorizeOffline"})};
const ComponentVariable LocalPreAuthorize = {
    {"AuthCtrlr"}, std::nullopt, std::optional<Variable>({"LocalPreAuthorize"})};
const ComponentVariable MasterPassGroupId = {
    {"AuthCtrlr"}, std::nullopt, std::optional<Variable>({"MasterPassGroupId"})};
const ComponentVariable OfflineTxForUnknownIdEnabled = {
    {"AuthCtrlr"}, std::nullopt, std::optional<Variable>({"Enabled"})};
const ComponentVariable AllowNewSessionsPendingFirmwareUpdate = {
    {"ChargingStation"}, std::nullopt, std::optional<Variable>({"AllowNewSessionsPendingFirmwareUpdate"})};
const ComponentVariable ChargingStationAvailabilityState = {
    {"ChargingStation"}, std::nullopt, std::optional<Variable>({"ChargingStationAvailabilityState"})};
const ComponentVariable ChargingStationAvailable = {
    {"ChargingStation"}, std::nullopt, std::optional<Variable>({"ChargingStationAvailable"})};
const ComponentVariable ChargingStationSupplyPhases = {
    {"ChargingStation"}, std::nullopt, std::optional<Variable>({"ChargingStationSupplyPhases"})};
const ComponentVariable DateTime = {{"ClockCtrlr"}, std::nullopt, std::optional<Variable>({"DateTime"})};
const ComponentVariable NextTimeOffsetTransitionDateTime = {
    {"ClockCtrlr"}, std::nullopt, std::optional<Variable>({"NextTimeOffsetTransitionDateTime"})};
const ComponentVariable NtpServerUri = {{"ClockCtrlr"}, std::nullopt, std::optional<Variable>({"NtpServerUri"})};
const ComponentVariable NtpSource = {{"ClockCtrlr"}, std::nullopt, std::optional<Variable>({"NtpSource"})};
const ComponentVariable TimeAdjustmentReportingThreshold = {
    {"ClockCtrlr"}, std::nullopt, std::optional<Variable>({"TimeAdjustmentReportingThreshold"})};
const ComponentVariable ClockCtrlrTimeOffset = {
    {"ClockCtrlr"}, std::nullopt, std::optional<Variable>({"ClockCtrlrTimeOffset"})};
const ComponentVariable ClockCtrlrTimeOffsetNextTransition = {
    {"ClockCtrlr"}, std::nullopt, std::optional<Variable>({"ClockCtrlrTimeOffsetNextTransition"})};
const ComponentVariable TimeSource = {{"ClockCtrlr"}, std::nullopt, std::optional<Variable>({"TimeSource"})};
const ComponentVariable TimeZone = {{"ClockCtrlr"}, std::nullopt, std::optional<Variable>({"TimeZone"})};
const ComponentVariable ConnectorAvailable = {
    {"Connector"}, std::nullopt, std::optional<Variable>({"ConnectorAvailable"})};
const ComponentVariable ConnectorType = {{"Connector"}, std::nullopt, std::optional<Variable>({"ConnectorType"})};
const ComponentVariable ConnectorSupplyPhases = {
    {"Connector"}, std::nullopt, std::optional<Variable>({"ConnectorSupplyPhases"})};
const ComponentVariable CustomImplementationEnabled = {
    {"CustomizationCtrlr"}, std::nullopt, std::optional<Variable>({"CustomImplementationEnabled"})};
const ComponentVariable DeviceDataCtrlrBytesPerMessageGetReport = {
    {"DeviceDataCtrlr"}, std::nullopt, std::optional<Variable>({"DeviceDataCtrlrBytesPerMessageGetReport"})};
const ComponentVariable DeviceDataCtrlrBytesPerMessageGetVariables = {
    {"DeviceDataCtrlr"}, std::nullopt, std::optional<Variable>({"DeviceDataCtrlrBytesPerMessageGetVariables"})};
const ComponentVariable DeviceDataCtrlrBytesPerMessageSetVariables = {
    {"DeviceDataCtrlr"}, std::nullopt, std::optional<Variable>({"DeviceDataCtrlrBytesPerMessageSetVariables"})};
const ComponentVariable ConfigurationValueSize = {
    {"DeviceDataCtrlr"}, std::nullopt, std::optional<Variable>({"ConfigurationValueSize"})};
const ComponentVariable DeviceDataCtrlrItemsPerMessageGetReport = {
    {"DeviceDataCtrlr"}, std::nullopt, std::optional<Variable>({"DeviceDataCtrlrItemsPerMessageGetReport"})};
const ComponentVariable DeviceDataCtrlrItemsPerMessageGetVariables = {
    {"DeviceDataCtrlr"}, std::nullopt, std::optional<Variable>({"DeviceDataCtrlrItemsPerMessageGetVariables"})};
const ComponentVariable DeviceDataCtrlrItemsPerMessageSetVariables = {
    {"DeviceDataCtrlr"}, std::nullopt, std::optional<Variable>({"DeviceDataCtrlrItemsPerMessageSetVariables"})};
const ComponentVariable ReportingValueSize = {
    {"DeviceDataCtrlr"}, std::nullopt, std::optional<Variable>({"ReportingValueSize"})};
const ComponentVariable DisplayMessageCtrlrAvailable = {
    {"DisplayMessageCtrlr"}, std::nullopt, std::optional<Variable>({"Available"})};
const ComponentVariable NumberOfDisplayMessages = {
    {"DisplayMessageCtrlr"}, std::nullopt, std::optional<Variable>({"NumberOfDisplayMessages"})};
const ComponentVariable DisplayMessageSupportedFormats = {
    {"DisplayMessageCtrlr"}, std::nullopt, std::optional<Variable>({"DisplayMessageSupportedFormats"})};
const ComponentVariable DisplayMessageSupportedPriorities = {
    {"DisplayMessageCtrlr"}, std::nullopt, std::optional<Variable>({"DisplayMessageSupportedPriorities"})};
const ComponentVariable AllowReset = {{"EVSE"}, std::nullopt, std::optional<Variable>({"AllowReset"})};
const ComponentVariable EVSEAvailable = {{"EVSE"}, std::nullopt, std::optional<Variable>({"EVSEAvailable"})};
const ComponentVariable Power = {{"EVSE"}, std::nullopt, std::optional<Variable>({"Power"})};
const ComponentVariable EVSESupplyPhases = {{"EVSE"}, std::nullopt, std::optional<Variable>({"EVSESupplyPhases"})};
const ComponentVariable CentralContractValidationAllowed = {
    {"ISO15118Ctrlr"}, std::nullopt, std::optional<Variable>({"CentralContractValidationAllowed"})};
const ComponentVariable ContractValidationOffline = {
    {"ISO15118Ctrlr"}, std::nullopt, std::optional<Variable>({"ContractValidationOffline"})};
const ComponentVariable RequestMeteringReceipt = {
    {"ISO15118Ctrlr"}, std::nullopt, std::optional<Variable>({"RequestMeteringReceipt"})};
const ComponentVariable CountryName = {{"ISO15118Ctrlr"}, std::nullopt, std::optional<Variable>({"CountryName"})};
const ComponentVariable ISO15118CtrlrOrganizationName = {
    {"ISO15118Ctrlr"}, std::nullopt, std::optional<Variable>({"ISO15118CtrlrOrganizationName"})};
const ComponentVariable PnCEnabled = {{"ISO15118Ctrlr"}, std::nullopt, std::optional<Variable>({"PnCEnabled"})};
const ComponentVariable V2GCertificateInstallationEnabled = {
    {"ISO15118Ctrlr"}, std::nullopt, std::optional<Variable>({"V2GCertificateInstallationEnabled"})};
const ComponentVariable ContractCertificateInstallationEnabled = {
    {"ISO15118Ctrlr"}, std::nullopt, std::optional<Variable>({"ContractCertificateInstallationEnabled"})};
const ComponentVariable LocalAuthListCtrlrAvailable = {
    {"LocalAuthListCtrlr"}, std::nullopt, std::optional<Variable>({"Available"})};
const ComponentVariable BytesPerMessageSendLocalList = {
    {"LocalAuthListCtrlr"}, std::nullopt, std::optional<Variable>({"BytesPerMessageSendLocalList"})};
const ComponentVariable LocalAuthListCtrlrEnabled = {
    {"LocalAuthListCtrlr"}, std::nullopt, std::optional<Variable>({"Enabled"})};
const ComponentVariable LocalAuthListCtrlrEntries = {
    {"LocalAuthListCtrlr"}, std::nullopt, std::optional<Variable>({"LocalAuthListCtrlrEntries"})};
const ComponentVariable ItemsPerMessageSendLocalList = {
    {"LocalAuthListCtrlr"}, std::nullopt, std::optional<Variable>({"ItemsPerMessageSendLocalList"})};
const ComponentVariable Storage = {{"LocalAuthListCtrlr"}, std::nullopt, std::optional<Variable>({"Storage"})};
const ComponentVariable MonitoringCtrlrAvailable = {
    {"MonitoringCtrlr"}, std::nullopt, std::optional<Variable>({"Available"})};
const ComponentVariable MonitoringCtrlrBytesPerMessageClearVariableMonitoring = {
    {"MonitoringCtrlr"}, std::nullopt, std::optional<Variable>({"BytesPerMessageClearVariableMonitoring"})};
const ComponentVariable MonitoringCtrlrBytesPerMessageSetVariableMonitoring = {
    {"MonitoringCtrlr"}, std::nullopt, std::optional<Variable>({"BytesPerMessageSetVariableMonitoring"})};
const ComponentVariable MonitoringCtrlrEnabled = {
    {"MonitoringCtrlr"}, std::nullopt, std::optional<Variable>({"Enabled"})};
const ComponentVariable MonitoringCtrlrItemsPerMessageClearVariableMonitoring = {
    {"MonitoringCtrlr"}, std::nullopt, std::optional<Variable>({"ItemsPerMessageClearVariableMonitoring"})};
const ComponentVariable MonitoringCtrlrItemsPerMessageSetVariableMonitoring = {
    {"MonitoringCtrlr"}, std::nullopt, std::optional<Variable>({"ItemsPerMessageSetVariableMonitoring"})};
const ComponentVariable OfflineQueuingSeverity = {
    {"MonitoringCtrlr"}, std::nullopt, std::optional<Variable>({"OfflineQueuingSeverity"})};
const ComponentVariable ActiveNetworkProfile = {
    {"OCPPCommCtrlr"}, std::nullopt, std::optional<Variable>({"ActiveNetworkProfile"})};
const ComponentVariable FileTransferProtocols = {
    {"OCPPCommCtrlr"}, std::nullopt, std::optional<Variable>({"FileTransferProtocols"})};
const ComponentVariable HeartbeatInterval = {
    {"OCPPCommCtrlr"}, std::nullopt, std::optional<Variable>({"HeartbeatInterval"})};
const ComponentVariable MessageTimeout = {{"OCPPCommCtrlr"}, std::nullopt, std::optional<Variable>({"MessageTimeout"})};
const ComponentVariable MessageAttemptIntervalTransactionEvent = {
    {"OCPPCommCtrlr"}, std::nullopt, std::optional<Variable>({"MessageAttemptIntervalTransactionEvent"})};
const ComponentVariable MessageAttemptsTransactionEvent = {
    {"OCPPCommCtrlr"}, std::nullopt, std::optional<Variable>({"MessageAttemptsTransactionEvent"})};
const ComponentVariable NetworkConfigurationPriority = {
    {"OCPPCommCtrlr"}, std::nullopt, std::optional<Variable>({"NetworkConfigurationPriority"})};
const ComponentVariable NetworkProfileConnectionAttempts = {
    {"OCPPCommCtrlr"}, std::nullopt, std::optional<Variable>({"NetworkProfileConnectionAttempts"})};
const ComponentVariable OfflineThreshold = {
    {"OCPPCommCtrlr"}, std::nullopt, std::optional<Variable>({"OfflineThreshold"})};
const ComponentVariable QueueAllMessages = {
    {"OCPPCommCtrlr"}, std::nullopt, std::optional<Variable>({"QueueAllMessages"})};
const ComponentVariable ResetRetries = {{"OCPPCommCtrlr"}, std::nullopt, std::optional<Variable>({"ResetRetries"})};
const ComponentVariable UnlockOnEVSideDisconnect = {
    {"OCPPCommCtrlr"}, std::nullopt, std::optional<Variable>({"UnlockOnEVSideDisconnect"})};
const ComponentVariable WebSocketPingInterval = {
    {"OCPPCommCtrlr"}, std::nullopt, std::optional<Variable>({"WebSocketPingInterval"})};
const ComponentVariable ReservationCtrlrAvailable = {
    {"ReservationCtrlr"}, std::nullopt, std::optional<Variable>({"Available"})};
const ComponentVariable ReservationCtrlrEnabled = {
    {"ReservationCtrlr"}, std::nullopt, std::optional<Variable>({"Enabled"})};
const ComponentVariable NonEvseSpecific = {
    {"ReservationCtrlr"}, std::nullopt, std::optional<Variable>({"NonEvseSpecific"})};
const ComponentVariable SampledDataCtrlrAvailable = {
    {"SampledDataCtrlr"}, std::nullopt, std::optional<Variable>({"Available"})};
const ComponentVariable SampledDataCtrlrEnabled = {
    {"SampledDataCtrlr"}, std::nullopt, std::optional<Variable>({"Enabled"})};
const ComponentVariable SampledDataSignReadings = {
    {"SampledDataCtrlr"}, std::nullopt, std::optional<Variable>({"SampledDataSignReadings"})};
const ComponentVariable SampledDataTxEndedInterval = {
    {"SampledDataCtrlr"}, std::nullopt, std::optional<Variable>({"SampledDataTxEndedInterval"})};
const ComponentVariable SampledDataTxEndedMeasurands = {
    {"SampledDataCtrlr"}, std::nullopt, std::optional<Variable>({"SampledDataTxEndedMeasurands"})};
const ComponentVariable SampledDataTxStartedMeasurands = {
    {"SampledDataCtrlr"}, std::nullopt, std::optional<Variable>({"SampledDataTxStartedMeasurands"})};
const ComponentVariable SampledDataTxUpdatedInterval = {
    {"SampledDataCtrlr"}, std::nullopt, std::optional<Variable>({"SampledDataTxUpdatedInterval"})};
const ComponentVariable SampledDataTxUpdatedMeasurands = {
    {"SampledDataCtrlr"}, std::nullopt, std::optional<Variable>({"SampledDataTxUpdatedMeasurands"})};
const ComponentVariable AdditionalRootCertificateCheck = {
    {"SecurityCtrlr"}, std::nullopt, std::optional<Variable>({"AdditionalRootCertificateCheck"})};
const ComponentVariable BasicAuthPassword = {
    {"SecurityCtrlr"}, std::nullopt, std::optional<Variable>({"BasicAuthPassword"})};
const ComponentVariable CertificateEntries = {
    {"SecurityCtrlr"}, std::nullopt, std::optional<Variable>({"CertificateEntries"})};
const ComponentVariable Identity = {{"SecurityCtrlr"}, std::nullopt, std::optional<Variable>({"Identity"})};
const ComponentVariable MaxCertificateChainSize = {
    {"SecurityCtrlr"}, std::nullopt, std::optional<Variable>({"MaxCertificateChainSize"})};
const ComponentVariable SecurityCtrlrOrganizationName = {
    {"SecurityCtrlr"}, std::nullopt, std::optional<Variable>({"SecurityCtrlrOrganizationName"})};
const ComponentVariable SecurityProfile = {
    {"SecurityCtrlr"}, std::nullopt, std::optional<Variable>({"SecurityProfile"})};
const ComponentVariable ACPhaseSwitchingSupported = {
    {"SmartChargingCtrlr"}, std::nullopt, std::optional<Variable>({"ACPhaseSwitchingSupported"})};
const ComponentVariable SmartChargingCtrlrAvailable = {
    {"SmartChargingCtrlr"}, std::nullopt, std::optional<Variable>({"SmartChargingCtrlrAvailable"})};
const ComponentVariable SmartChargingCtrlrEnabled = {
    {"SmartChargingCtrlr"}, std::nullopt, std::optional<Variable>({"SmartChargingCtrlrEnabled"})};
const ComponentVariable SmartChargingCtrlrEntriesChargingProfiles = {
    {"SmartChargingCtrlr"}, std::nullopt, std::optional<Variable>({"SmartChargingCtrlrEntriesChargingProfiles"})};
const ComponentVariable ExternalControlSignalsEnabled = {
    {"SmartChargingCtrlr"}, std::nullopt, std::optional<Variable>({"ExternalControlSignalsEnabled"})};
const ComponentVariable LimitChangeSignificance = {
    {"SmartChargingCtrlr"}, std::nullopt, std::optional<Variable>({"LimitChangeSignificance"})};
const ComponentVariable NotifyChargingLimitWithSchedules = {
    {"SmartChargingCtrlr"}, std::nullopt, std::optional<Variable>({"NotifyChargingLimitWithSchedules"})};
const ComponentVariable PeriodsPerSchedule = {
    {"SmartChargingCtrlr"}, std::nullopt, std::optional<Variable>({"PeriodsPerSchedule"})};
const ComponentVariable Phases3to1 = {{"SmartChargingCtrlr"}, std::nullopt, std::optional<Variable>({"Phases3to1"})};
const ComponentVariable ChargingProfileMaxStackLevel = {
    {"SmartChargingCtrlr"}, std::nullopt, std::optional<Variable>({"ChargingProfileMaxStackLevel"})};
const ComponentVariable ChargingScheduleChargingRateUnit = {
    {"SmartChargingCtrlr"}, std::nullopt, std::optional<Variable>({"ChargingScheduleChargingRateUnit"})};
const ComponentVariable TariffCostCtrlrAvailableTariff = {
    {"TariffCostCtrlr"}, std::nullopt, std::optional<Variable>({"TariffCostCtrlrAvailableTariff"})};
const ComponentVariable TariffCostCtrlrAvailableCost = {
    {"TariffCostCtrlr"}, std::nullopt, std::optional<Variable>({"TariffCostCtrlrAvailableCost"})};
const ComponentVariable Currency = {{"TariffCostCtrlr"}, std::nullopt, std::optional<Variable>({"Currency"})};
const ComponentVariable TariffCostCtrlrEnabledTariff = {
    {"TariffCostCtrlr"}, std::nullopt, std::optional<Variable>({"TariffCostCtrlrEnabledTariff"})};
const ComponentVariable TariffCostCtrlrEnabledCost = {
    {"TariffCostCtrlr"}, std::nullopt, std::optional<Variable>({"TariffCostCtrlrEnabledCost"})};
const ComponentVariable TariffFallbackMessage = {
    {"TariffCostCtrlr"}, std::nullopt, std::optional<Variable>({"TariffFallbackMessage"})};
const ComponentVariable TotalCostFallbackMessage = {
    {"TariffCostCtrlr"}, std::nullopt, std::optional<Variable>({"TotalCostFallbackMessage"})};
const ComponentVariable EVConnectionTimeOut = {
    {"TxCtrlr"}, std::nullopt, std::optional<Variable>({"EVConnectionTimeOut"})};
const ComponentVariable MaxEnergyOnInvalidId = {
    {"TxCtrlr"}, std::nullopt, std::optional<Variable>({"MaxEnergyOnInvalidId"})};
const ComponentVariable StopTxOnEVSideDisconnect = {
    {"TxCtrlr"}, std::nullopt, std::optional<Variable>({"StopTxOnEVSideDisconnect"})};
const ComponentVariable StopTxOnInvalidId = {{"TxCtrlr"}, std::nullopt, std::optional<Variable>({"StopTxOnInvalidId"})};
const ComponentVariable TxBeforeAcceptedEnabled = {
    {"TxCtrlr"}, std::nullopt, std::optional<Variable>({"TxBeforeAcceptedEnabled"})};
const ComponentVariable TxStartPoint = {{"TxCtrlr"}, std::nullopt, std::optional<Variable>({"TxStartPoint"})};
const ComponentVariable TxStopPoint = {{"TxCtrlr"}, std::nullopt, std::optional<Variable>({"TxStopPoint"})};

} // namespace ControllerComponentVariables

/// \brief Response to requesting a value from the device model
/// \tparam T
template <typename T> struct RequestDeviceModelResponse {
    std::optional<T> value;
    GetVariableStatusEnum status;
};

/// \brief Converts the given \p value to the specific type based on the template parameter
/// \tparam T
/// \param value
/// \return
template <typename T> T to_specific_type(const std::string& value) {
    if constexpr (std::is_same<T, std::string>::value) {
        return value;
    } else if constexpr (std::is_same<T, int>::value) {
        return std::stoi(value);
    } else if constexpr (std::is_same<T, double>::value) {
        return std::stod(value);
    } else if constexpr (std::is_same<T, DateTime>::value) {
        return DateTime(value);
    } else if constexpr (std::is_same<T, bool>::value) {
        return ocpp::conversions::string_to_bool(value);
    } else {
        EVLOG_AND_THROW(std::runtime_error("Requested unknown datatype"));
    }
}

/// \brief This class manages access to the device model storage and provides functionality to support the use cases
/// defined in the functional block Provisioning
class DeviceModel {

private:
    std::map<Component, std::map<Variable, VariableMetaData>> device_model;
    std::unique_ptr<DeviceModelStorage> storage;

    bool component_criteria_match(const Component& component,
                                  const std::vector<ComponentCriterionEnum>& component_criteria);

public:
    DeviceModel();

    /// \brief Direct access to value of a VariableAttribute for the given component, variable and attribute_enum. This
    /// should only be called for variables that have a role standardized in the OCPP2.0.1 specification.
    /// \tparam T datatype of the value that is requested
    /// \param component_variable Combination of Component and Variable that identifies the Variable
    /// \param attribute_enum
    /// \return the requested value from the device model storage
    template <typename T>
    T get_variable_attribute_value(const ComponentVariable& component_variable,
                                   const AttributeEnum& attribute_enum = AttributeEnum::Actual) {
        const auto response = this->request_variable_attribute_value<T>(
            component_variable.component, component_variable.variable.value(), attribute_enum);
        if (response.value.has_value()) {
            return response.value.value();
        } else {
            EVLOG_critical
                << "Directly requested value for ComponentVariable that doesn't exist in the device model storage: "
                << component_variable;
            EVLOG_AND_THROW(std::runtime_error(
                "Directly requested value for ComponentVariable that doesn't exist in the device model storage."));
        }
    };

    /// \brief  Access to std::optional of a VariableAttribute for the given component, variable and attribute_enum.
    /// \tparam T Tatatype of the value that is requested
    /// \param component_variable Combination of Component and Variable that identifies the Variable
    /// \param attribute_enum
    /// \return std::optional<T> if the combination of \p component_variable and \p attribute_enum could successfully
    /// requested from the storage and a value is present for this combination, else std::nullopt .
    template <typename T>
    std::optional<T>
    get_variable_attribute_optional_value(const ComponentVariable& component_variable,
                                          const AttributeEnum& attribute_enum = AttributeEnum::Actual) {
        const auto response = this->request_variable_attribute_value<T>(
            component_variable.component, component_variable.variable.value(), attribute_enum);
        if (response.status == GetVariableStatusEnum::Accepted) {
            return response.value.value();
        } else {
            return std::nullopt;
        }
    };

    /// \brief Requests a value of a VariableAttribute specified by combination of \p component and \p variable from the
    /// device model storage
    /// \tparam T datatype of the value that is requested
    /// \param component
    /// \param variable
    /// \param attribute_enum
    /// \return Response to request that contains status of the request and the requested value as std::optional<T> .
    /// The value is present if the status is GetVariableStatusEnum::Accepted
    template <typename T>
    RequestDeviceModelResponse<T> request_variable_attribute_value(const Component& component, const Variable& variable,
                                                                   const AttributeEnum& attribute_enum) {
        RequestDeviceModelResponse<T> response;
        if (this->device_model.find(component) != this->device_model.end()) {
            // component is present
            const auto _component = this->device_model[component];
            if (_component.find(variable) != _component.end()) {
                // variable is present
                const auto attribute_opt = this->storage->get_variable_attribute(component, variable, attribute_enum);
                if (attribute_opt.has_value()) {
                    const auto attribute = attribute_opt.value();
                    if (attribute.value.has_value()) {
                        const auto value = attribute.value.value().get();
                        response.status = GetVariableStatusEnum::Accepted;
                        response.value = to_specific_type<T>(value); // convert string value to specific type
                    } else {
                        // attribute is present but no value is present
                        response.status = GetVariableStatusEnum::NotSupportedAttributeType;
                    }
                } else {
                    response.status = GetVariableStatusEnum::NotSupportedAttributeType;
                }
            } else {
                response.status = GetVariableStatusEnum::UnknownVariable;
            }
        } else {
            response.status = GetVariableStatusEnum::UnknownComponent;
        }
        return response;
    }

    /// \brief Sets the variable attribute \p value specified by \p component , \p variable and \p attribute_enum
    /// \param component
    /// \param variable
    /// \param attribute_enum
    /// \param value
    /// \return Result of the requested operation
    SetVariableStatusEnum set_variable_attribute_value(const Component& component, const Variable& variable,
                                                       const AttributeEnum& attribute_enum, const std::string& value);

    /// \brief Gets the VariableMetaData for the given \p component and \p variable
    /// \param component
    /// \param variable
    /// \return VariableMetaData or std::nullopt if \p component or \p variable not present
    std::optional<VariableMetaData> get_variable_meta_data(const Component& component, const Variable& variable);

    /// \brief Gets the ReportData for the specifed filter \p report_base \p component_variables and \p
    /// component_criteria
    /// \param report_base
    /// \param component_variables
    /// \param component_criteria
    /// \return
    std::vector<ReportData>
    get_report_data(const std::optional<ReportBaseEnum>& report_base = std::nullopt,
                    const std::optional<std::vector<ComponentVariable>>& component_variables = std::nullopt,
                    const std::optional<std::vector<ComponentCriterionEnum>>& component_criteria = std::nullopt);
};

} // namespace v201
} // namespace ocpp

#endif // DEVICE_MODEL_HPP