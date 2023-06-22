// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 -  Pionix GmbH and Contributors to EVerest

#ifndef OCPP_V201_CONTROLLER_COMPONENT_VARIABLES_HPP
#define OCPP_V201_CONTROLLER_COMPONENT_VARIABLES_HPP

#include <ocpp/v201/ocpp_types.hpp>

namespace ocpp {
namespace v201 {
namespace ControllerComponentVariables {

const ComponentVariable InternalCtrlrEnabled = {
    {"InternalCtrlr"}, std::nullopt, std::optional<Variable>({"InternalCtrlrEnabled"})};
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
    {"AlignedDataCtrlr"}, std::nullopt, std::optional<Variable>({"AlignedDataCtrlrEnabled"})};
const ComponentVariable AlignedDataCtrlrAvailable = {
    {"AlignedDataCtrlr"}, std::nullopt, std::optional<Variable>({"AlignedDataCtrlrAvailable"})};
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
    {"AuthCacheCtrlr"}, std::nullopt, std::optional<Variable>({"AuthCacheCtrlrAvailable"})};
const ComponentVariable AuthCacheCtrlrEnabled = {
    {"AuthCacheCtrlr"}, std::nullopt, std::optional<Variable>({"AuthCacheCtrlrEnabled"})};
const ComponentVariable AuthCacheLifeTime = {
    {"AuthCacheCtrlr"}, std::nullopt, std::optional<Variable>({"AuthCacheLifeTime"})};
const ComponentVariable AuthCachePolicy = {
    {"AuthCacheCtrlr"}, std::nullopt, std::optional<Variable>({"AuthCachePolicy"})};
const ComponentVariable AuthCacheStorage = {
    {"AuthCacheCtrlr"}, std::nullopt, std::optional<Variable>({"AuthCacheStorage"})};
const ComponentVariable AuthCtrlrEnabled = {{"AuthCtrlr"}, std::nullopt, std::optional<Variable>({"AuthCtrlrEnabled"})};
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
    {"AuthCtrlr"}, std::nullopt, std::optional<Variable>({"OfflineTxForUnknownIdEnabled"})};
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
    {"DisplayMessageCtrlr"}, std::nullopt, std::optional<Variable>({"DisplayMessageCtrlrAvailable"})};
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
    {"LocalAuthListCtrlr"}, std::nullopt, std::optional<Variable>({"LocalAuthListCtrlrAvailable"})};
const ComponentVariable BytesPerMessageSendLocalList = {
    {"LocalAuthListCtrlr"}, std::nullopt, std::optional<Variable>({"BytesPerMessageSendLocalList"})};
const ComponentVariable LocalAuthListCtrlrEnabled = {
    {"LocalAuthListCtrlr"}, std::nullopt, std::optional<Variable>({"LocalAuthListCtrlrEnabled"})};
const ComponentVariable LocalAuthListCtrlrEntries = {
    {"LocalAuthListCtrlr"}, std::nullopt, std::optional<Variable>({"LocalAuthListCtrlrEntries"})};
const ComponentVariable ItemsPerMessageSendLocalList = {
    {"LocalAuthListCtrlr"}, std::nullopt, std::optional<Variable>({"ItemsPerMessageSendLocalList"})};
const ComponentVariable Storage = {{"LocalAuthListCtrlr"}, std::nullopt, std::optional<Variable>({"Storage"})};
const ComponentVariable MonitoringCtrlrAvailable = {
    {"MonitoringCtrlr"}, std::nullopt, std::optional<Variable>({"MonitoringCtrlrAvailable"})};
const ComponentVariable MonitoringCtrlrBytesPerMessageClearVariableMonitoring = {
    {"MonitoringCtrlr"},
    std::nullopt,
    std::optional<Variable>({"MonitoringCtrlrBytesPerMessageClearVariableMonitoring"})};
const ComponentVariable MonitoringCtrlrBytesPerMessageSetVariableMonitoring = {
    {"MonitoringCtrlr"},
    std::nullopt,
    std::optional<Variable>({"MonitoringCtrlrBytesPerMessageSetVariableMonitoring"})};
const ComponentVariable MonitoringCtrlrEnabled = {
    {"MonitoringCtrlr"}, std::nullopt, std::optional<Variable>({"MonitoringCtrlrEnabled"})};
const ComponentVariable MonitoringCtrlrItemsPerMessageClearVariableMonitoring = {
    {"MonitoringCtrlr"},
    std::nullopt,
    std::optional<Variable>({"MonitoringCtrlrItemsPerMessageClearVariableMonitoring"})};
const ComponentVariable MonitoringCtrlrItemsPerMessageSetVariableMonitoring = {
    {"MonitoringCtrlr"},
    std::nullopt,
    std::optional<Variable>({"MonitoringCtrlrItemsPerMessageSetVariableMonitoring"})};
const ComponentVariable OfflineQueuingSeverity = {
    {"MonitoringCtrlr"}, std::nullopt, std::optional<Variable>({"OfflineQueuingSeverity"})};
const ComponentVariable ActiveNetworkProfile = {
    {"OCPPCommCtrlr"}, std::nullopt, std::optional<Variable>({"ActiveNetworkProfile"})};
const ComponentVariable FileTransferProtocols = {
    {"OCPPCommCtrlr"}, std::nullopt, std::optional<Variable>({"FileTransferProtocols"})};
const ComponentVariable HeartbeatInterval = {
    {"OCPPCommCtrlr"}, std::nullopt, std::optional<Variable>({"HeartbeatInterval"})};
const ComponentVariable MessageTimeout = {{"OCPPCommCtrlr"}, std::nullopt, std::optional<Variable>({"MessageTimeout"})};
const ComponentVariable MessageAttemptInterval = {
    {"OCPPCommCtrlr"}, std::nullopt, std::optional<Variable>({"MessageAttemptInterval"})};
const ComponentVariable MessageAttempts = {
    {"OCPPCommCtrlr"}, std::nullopt, std::optional<Variable>({"MessageAttempts"})};
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
    {"ReservationCtrlr"}, std::nullopt, std::optional<Variable>({"ReservationCtrlrAvailable"})};
const ComponentVariable ReservationCtrlrEnabled = {
    {"ReservationCtrlr"}, std::nullopt, std::optional<Variable>({"ReservationCtrlrEnabled"})};
const ComponentVariable NonEvseSpecific = {
    {"ReservationCtrlr"}, std::nullopt, std::optional<Variable>({"NonEvseSpecific"})};
const ComponentVariable SampledDataCtrlrAvailable = {
    {"SampledDataCtrlr"}, std::nullopt, std::optional<Variable>({"SampledDataCtrlrAvailable"})};
const ComponentVariable SampledDataCtrlrEnabled = {
    {"SampledDataCtrlr"}, std::nullopt, std::optional<Variable>({"SampledDataCtrlrEnabled"})};
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
} // namespace v201
} // namespace ocpp

#endif // OCPP_V201_CONTROLLER_COMPONENT_VARIABLES_HPP