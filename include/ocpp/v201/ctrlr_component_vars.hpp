// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 -  Pionix GmbH and Contributors to EVerest

#ifndef OCPP_V201_CONTROLLER_COMPONENT_VARIABLES_HPP
#define OCPP_V201_CONTROLLER_COMPONENT_VARIABLES_HPP

#include <ocpp/v201/ocpp_types.hpp>

namespace ocpp {
namespace v201 {
namespace ControllerComponentVariables {

    const ComponentVariable AlignedDataCtrlrEnabled = {{"AlignedDataCtrlr"}, {"Enabled"}};
    const ComponentVariable AlignedDataCtrlrAvailable = {{"AlignedDataCtrlr"}, {"Available"}};
    const ComponentVariable AlignedDataCtrlrAlignedDataInterval = {{"AlignedDataCtrlr"}, {"AlignedDataInterval"}};
    const ComponentVariable AlignedDataCtrlrAlignedDataMeasurands = {{"AlignedDataCtrlr"}, {"AlignedDataMeasurands"}};
    const ComponentVariable AlignedDataCtrlrAlignedDataSendDuringIdle = {{"AlignedDataCtrlr"},
                                                                         {"AlignedDataSendDuringIdle"}};
    const ComponentVariable AlignedDataCtrlrAlignedDataSignReadings = {{"AlignedDataCtrlr"},
                                                                       {"AlignedDataSignReadings"}};
    const ComponentVariable AlignedDataCtrlrAlignedDataTxEndedInterval = {{"AlignedDataCtrlr"},
                                                                          {"AlignedDataTxEndedInterval"}};
    const ComponentVariable AlignedDataCtrlrAlignedDataTxEndedMeasurands = {{"AlignedDataCtrlr"},
                                                                            {"AlignedDataTxEndedMeasurands"}};
    const ComponentVariable AuthCacheCtrlrAvailable = {{"AuthCacheCtrlr"}, {"Available"}};
    const ComponentVariable AuthCacheCtrlrEnabled = {{"AuthCacheCtrlr"}, {"Enabled"}};
    const ComponentVariable AuthCacheCtrlrAuthCacheLifeTime = {{"AuthCacheCtrlr"}, {"AuthCacheLifeTime"}};
    const ComponentVariable AuthCacheCtrlrAuthCachePolicy = {{"AuthCacheCtrlr"}, {"AuthCachePolicy"}};
    const ComponentVariable AuthCacheCtrlrAuthCacheStorage = {{"AuthCacheCtrlr"}, {"AuthCacheStorage"}};
    const ComponentVariable AuthCtrlrEnabled = {{"AuthCtrlr"}, {"Enabled"}};
    const ComponentVariable AuthCtrlrAdditionalInfoItemsPerMessage = {{"AuthCtrlr"}, {"AdditionalInfoItemsPerMessage"}};
    const ComponentVariable AuthCtrlrAuthorizeRemoteStart = {{"AuthCtrlr"}, {"AuthorizeRemoteStart"}};
    const ComponentVariable AuthCtrlrLocalAuthorizeOffline = {{"AuthCtrlr"}, {"LocalAuthorizeOffline"}};
    const ComponentVariable AuthCtrlrLocalPreAuthorize = {{"AuthCtrlr"}, {"LocalPreAuthorize"}};
    const ComponentVariable AuthCtrlrMasterPassGroupId = {{"AuthCtrlr"}, {"MasterPassGroupId"}};
    const ComponentVariable AuthCtrlrOfflineTxForUnknownIdEnabled = {{"AuthCtrlr"}, {"OfflineTxForUnknownIdEnabled"}};
    const ComponentVariable ChargingStationAllowNewSessionsPendingFirmwareUpdate = {
        {"ChargingStation"}, {"AllowNewSessionsPendingFirmwareUpdate"}};
    const ComponentVariable ChargingStationAvailabilityState = {{"ChargingStation"}, {"AvailabilityState"}};
    const ComponentVariable ChargingStationAvailable = {{"ChargingStation"}, {"Available"}};
    const ComponentVariable ChargingStationSupplyPhases = {{"ChargingStation"}, {"SupplyPhases"}};
    const ComponentVariable ClockCtrlrDateTime = {{"ClockCtrlr"}, {"DateTime"}};
    const ComponentVariable ClockCtrlrNextTimeOffsetTransitionDateTime = {{"ClockCtrlr"},
                                                                          {"NextTimeOffsetTransitionDateTime"}};
    const ComponentVariable ClockCtrlrNtpServerUri = {{"ClockCtrlr"}, {"NtpServerUri"}};
    const ComponentVariable ClockCtrlrNtpSource = {{"ClockCtrlr"}, {"NtpSource"}};
    const ComponentVariable ClockCtrlrTimeAdjustmentReportingThreshold = {{"ClockCtrlr"},
                                                                          {"TimeAdjustmentReportingThreshold"}};
    const ComponentVariable ClockCtrlrTimeOffset = {{"ClockCtrlr"}, {"TimeOffset"}};
    const ComponentVariable ClockCtrlrTimeOffset = {{"ClockCtrlr"}, {"TimeOffset"}};
    const ComponentVariable ClockCtrlrTimeSource = {{"ClockCtrlr"}, {"TimeSource"}};
    const ComponentVariable ClockCtrlrTimeZone = {{"ClockCtrlr"}, {"TimeZone"}};
    const ComponentVariable ConnectorAvailable = {{"Connector"}, {"Available"}};
    const ComponentVariable ConnectorConnectorType = {{"Connector"}, {"ConnectorType"}};
    const ComponentVariable ConnectorSupplyPhases = {{"Connector"}, {"SupplyPhases"}};
    const ComponentVariable CustomizationCtrlrCustomImplementationEnabled = {{"CustomizationCtrlr"},
                                                                             {"CustomImplementationEnabled"}};
    const ComponentVariable DeviceDataCtrlrBytesPerMessage = {{"DeviceDataCtrlr"}, {"BytesPerMessage"}};
    const ComponentVariable DeviceDataCtrlrBytesPerMessage = {{"DeviceDataCtrlr"}, {"BytesPerMessage"}};
    const ComponentVariable DeviceDataCtrlrBytesPerMessage = {{"DeviceDataCtrlr"}, {"BytesPerMessage"}};
    const ComponentVariable DeviceDataCtrlrConfigurationValueSize = {{"DeviceDataCtrlr"}, {"ConfigurationValueSize"}};
    const ComponentVariable DeviceDataCtrlrItemsPerMessage = {{"DeviceDataCtrlr"}, {"ItemsPerMessage"}};
    const ComponentVariable DeviceDataCtrlrItemsPerMessage = {{"DeviceDataCtrlr"}, {"ItemsPerMessage"}};
    const ComponentVariable DeviceDataCtrlrItemsPerMessage = {{"DeviceDataCtrlr"}, {"ItemsPerMessage"}};
    const ComponentVariable DeviceDataCtrlrReportingValueSize = {{"DeviceDataCtrlr"}, {"ReportingValueSize"}};
    const ComponentVariable DisplayMessageCtrlrAvailable = {{"DisplayMessageCtrlr"}, {"Available"}};
    const ComponentVariable DisplayMessageCtrlrNumberOfDisplayMessages = {{"DisplayMessageCtrlr"},
                                                                          {"NumberOfDisplayMessages"}};
    const ComponentVariable DisplayMessageCtrlrDisplayMessageSupportedFormats = {{"DisplayMessageCtrlr"},
                                                                                 {"DisplayMessageSupportedFormats"}};
    const ComponentVariable DisplayMessageCtrlrDisplayMessageSupportedPriorities = {
        {"DisplayMessageCtrlr"}, {"DisplayMessageSupportedPriorities"}};
    const ComponentVariable EVSEAllowReset = {{"EVSE"}, {"AllowReset"}};
    const ComponentVariable EVSEAvailable = {{"EVSE"}, {"Available"}};
    const ComponentVariable EVSEPower = {{"EVSE"}, {"Power"}};
    const ComponentVariable EVSESupplyPhases = {{"EVSE"}, {"SupplyPhases"}};
    const ComponentVariable ISO15118CtrlrCentralContractValidationAllowed = {{"ISO15118Ctrlr"},
                                                                             {"CentralContractValidationAllowed"}};
    const ComponentVariable ISO15118CtrlrContractValidationOffline = {{"ISO15118Ctrlr"}, {"ContractValidationOffline"}};
    const ComponentVariable ISO15118CtrlrRequestMeteringReceipt = {{"ISO15118Ctrlr"}, {"RequestMeteringReceipt"}};
    const ComponentVariable ISO15118CtrlrCountryName = {{"ISO15118Ctrlr"}, {"CountryName"}};
    const ComponentVariable ISO15118CtrlrOrganizationName = {{"ISO15118Ctrlr"}, {"OrganizationName"}};
    const ComponentVariable ISO15118CtrlrPnCEnabled = {{"ISO15118Ctrlr"}, {"PnCEnabled"}};
    const ComponentVariable ISO15118CtrlrV2GCertificateInstallationEnabled = {{"ISO15118Ctrlr"},
                                                                              {"V2GCertificateInstallationEnabled"}};
    const ComponentVariable ISO15118CtrlrContractCertificateInstallationEnabled = {
        {"ISO15118Ctrlr"}, {"ContractCertificateInstallationEnabled"}};
    const ComponentVariable LocalAuthListCtrlrAvailable = {{"LocalAuthListCtrlr"}, {"Available"}};
    const ComponentVariable LocalAuthListCtrlrBytesPerMessageSendLocalList = {{"LocalAuthListCtrlr"},
                                                                              {"BytesPerMessageSendLocalList"}};
    const ComponentVariable LocalAuthListCtrlrEnabled = {{"LocalAuthListCtrlr"}, {"Enabled"}};
    const ComponentVariable LocalAuthListCtrlrEntries = {{"LocalAuthListCtrlr"}, {"Entries"}};
    const ComponentVariable LocalAuthListCtrlrItemsPerMessageSendLocalList = {{"LocalAuthListCtrlr"},
                                                                              {"ItemsPerMessageSendLocalList"}};
    const ComponentVariable LocalAuthListCtrlrStorage = {{"LocalAuthListCtrlr"}, {"Storage"}};
    const ComponentVariable MonitoringCtrlrAvailable = {{"MonitoringCtrlr"}, {"Available"}};
    const ComponentVariable MonitoringCtrlrBytesPerMessage = {{"MonitoringCtrlr"}, {"BytesPerMessage"}};
    const ComponentVariable MonitoringCtrlrBytesPerMessage = {{"MonitoringCtrlr"}, {"BytesPerMessage"}};
    const ComponentVariable MonitoringCtrlrEnabled = {{"MonitoringCtrlr"}, {"Enabled"}};
    const ComponentVariable MonitoringCtrlrItemsPerMessage = {{"MonitoringCtrlr"}, {"ItemsPerMessage"}};
    const ComponentVariable MonitoringCtrlrItemsPerMessage = {{"MonitoringCtrlr"}, {"ItemsPerMessage"}};
    const ComponentVariable MonitoringCtrlrOfflineQueuingSeverity = {{"MonitoringCtrlr"}, {"OfflineQueuingSeverity"}};
    const ComponentVariable OCPPCommCtrlrActiveNetworkProfile = {{"OCPPCommCtrlr"}, {"ActiveNetworkProfile"}};
    const ComponentVariable OCPPCommCtrlrFileTransferProtocols = {{"OCPPCommCtrlr"}, {"FileTransferProtocols"}};
    const ComponentVariable OCPPCommCtrlrHeartbeatInterval = {{"OCPPCommCtrlr"}, {"HeartbeatInterval"}};
    const ComponentVariable OCPPCommCtrlrMessageTimeout = {{"OCPPCommCtrlr"}, {"MessageTimeout"}};
    const ComponentVariable OCPPCommCtrlrMessageAttemptInterval = {{"OCPPCommCtrlr"}, {"MessageAttemptInterval"}};
    const ComponentVariable OCPPCommCtrlrMessageAttempts = {{"OCPPCommCtrlr"}, {"MessageAttempts"}};
    const ComponentVariable OCPPCommCtrlrNetworkConfigurationPriority = {{"OCPPCommCtrlr"},
                                                                         {"NetworkConfigurationPriority"}};
    const ComponentVariable OCPPCommCtrlrNetworkProfileConnectionAttempts = {{"OCPPCommCtrlr"},
                                                                             {"NetworkProfileConnectionAttempts"}};
    const ComponentVariable OCPPCommCtrlrOfflineThreshold = {{"OCPPCommCtrlr"}, {"OfflineThreshold"}};
    const ComponentVariable OCPPCommCtrlrQueueAllMessages = {{"OCPPCommCtrlr"}, {"QueueAllMessages"}};
    const ComponentVariable OCPPCommCtrlrResetRetries = {{"OCPPCommCtrlr"}, {"ResetRetries"}};
    const ComponentVariable OCPPCommCtrlrUnlockOnEVSideDisconnect = {{"OCPPCommCtrlr"}, {"UnlockOnEVSideDisconnect"}};
    const ComponentVariable OCPPCommCtrlrWebSocketPingInterval = {{"OCPPCommCtrlr"}, {"WebSocketPingInterval"}};
    const ComponentVariable ReservationCtrlrAvailable = {{"ReservationCtrlr"}, {"Available"}};
    const ComponentVariable ReservationCtrlrEnabled = {{"ReservationCtrlr"}, {"Enabled"}};
    const ComponentVariable ReservationCtrlrNonEvseSpecific = {{"ReservationCtrlr"}, {"NonEvseSpecific"}};
    const ComponentVariable SampledDataCtrlrAvailable = {{"SampledDataCtrlr"}, {"Available"}};
    const ComponentVariable SampledDataCtrlrEnabled = {{"SampledDataCtrlr"}, {"Enabled"}};
    const ComponentVariable SampledDataCtrlrSampledDataSignReadings = {{"SampledDataCtrlr"},
                                                                       {"SampledDataSignReadings"}};
    const ComponentVariable SampledDataCtrlrSampledDataTxEndedInterval = {{"SampledDataCtrlr"},
                                                                          {"SampledDataTxEndedInterval"}};
    const ComponentVariable SampledDataCtrlrSampledDataTxEndedMeasurands = {{"SampledDataCtrlr"},
                                                                            {"SampledDataTxEndedMeasurands"}};
    const ComponentVariable SampledDataCtrlrSampledDataTxStartedMeasurands = {{"SampledDataCtrlr"},
                                                                              {"SampledDataTxStartedMeasurands"}};
    const ComponentVariable SampledDataCtrlrSampledDataTxUpdatedInterval = {{"SampledDataCtrlr"},
                                                                            {"SampledDataTxUpdatedInterval"}};
    const ComponentVariable SampledDataCtrlrSampledDataTxUpdatedMeasurands = {{"SampledDataCtrlr"},
                                                                              {"SampledDataTxUpdatedMeasurands"}};
    const ComponentVariable SecurityCtrlrAdditionalRootCertificateCheck = {{"SecurityCtrlr"},
                                                                           {"AdditionalRootCertificateCheck"}};
    const ComponentVariable SecurityCtrlrBasicAuthPassword = {{"SecurityCtrlr"}, {"BasicAuthPassword"}};
    const ComponentVariable SecurityCtrlrCertificateEntries = {{"SecurityCtrlr"}, {"CertificateEntries"}};
    const ComponentVariable SecurityCtrlrIdentity = {{"SecurityCtrlr"}, {"Identity"}};
    const ComponentVariable SecurityCtrlrMaxCertificateChainSize = {{"SecurityCtrlr"}, {"MaxCertificateChainSize"}};
    const ComponentVariable SecurityCtrlrOrganizationName = {{"SecurityCtrlr"}, {"OrganizationName"}};
    const ComponentVariable SecurityCtrlrSecurityProfile = {{"SecurityCtrlr"}, {"SecurityProfile"}};
    const ComponentVariable SmartChargingCtrlrACPhaseSwitchingSupported = {{"SmartChargingCtrlr"},
                                                                           {"ACPhaseSwitchingSupported"}};
    const ComponentVariable SmartChargingCtrlrAvailable = {{"SmartChargingCtrlr"}, {"Available"}};
    const ComponentVariable SmartChargingCtrlrEnabled = {{"SmartChargingCtrlr"}, {"Enabled"}};
    const ComponentVariable SmartChargingCtrlrEntries = {{"SmartChargingCtrlr"}, {"Entries"}};
    const ComponentVariable SmartChargingCtrlrExternalControlSignalsEnabled = {{"SmartChargingCtrlr"},
                                                                               {"ExternalControlSignalsEnabled"}};
    const ComponentVariable SmartChargingCtrlrLimitChangeSignificance = {{"SmartChargingCtrlr"},
                                                                         {"LimitChangeSignificance"}};
    const ComponentVariable SmartChargingCtrlrNotifyChargingLimitWithSchedules = {{"SmartChargingCtrlr"},
                                                                                  {"NotifyChargingLimitWithSchedules"}};
    const ComponentVariable SmartChargingCtrlrPeriodsPerSchedule = {{"SmartChargingCtrlr"}, {"PeriodsPerSchedule"}};
    const ComponentVariable SmartChargingCtrlrPhases3to1 = {{"SmartChargingCtrlr"}, {"Phases3to1"}};
    const ComponentVariable SmartChargingCtrlrChargingProfileMaxStackLevel = {{"SmartChargingCtrlr"},
                                                                              {"ChargingProfileMaxStackLevel"}};
    const ComponentVariable SmartChargingCtrlrChargingScheduleChargingRateUnit = {{"SmartChargingCtrlr"},
                                                                                  {"ChargingScheduleChargingRateUnit"}};
    const ComponentVariable TariffCostCtrlrAvailable = {{"TariffCostCtrlr"}, {"Available"}};
    const ComponentVariable TariffCostCtrlrAvailable = {{"TariffCostCtrlr"}, {"Available"}};
    const ComponentVariable TariffCostCtrlrCurrency = {{"TariffCostCtrlr"}, {"Currency"}};
    const ComponentVariable TariffCostCtrlrEnabled = {{"TariffCostCtrlr"}, {"Enabled"}};
    const ComponentVariable TariffCostCtrlrEnabled = {{"TariffCostCtrlr"}, {"Enabled"}};
    const ComponentVariable TariffCostCtrlrTariffFallbackMessage = {{"TariffCostCtrlr"}, {"TariffFallbackMessage"}};
    const ComponentVariable TariffCostCtrlrTotalCostFallbackMessage = {{"TariffCostCtrlr"},
                                                                       {"TotalCostFallbackMessage"}};
    const ComponentVariable TxCtrlrEVConnectionTimeOut = {{"TxCtrlr"}, {"EVConnectionTimeOut"}};
    const ComponentVariable TxCtrlrMaxEnergyOnInvalidId = {{"TxCtrlr"}, {"MaxEnergyOnInvalidId"}};
    const ComponentVariable TxCtrlrStopTxOnEVSideDisconnect = {{"TxCtrlr"}, {"StopTxOnEVSideDisconnect"}};
    const ComponentVariable TxCtrlrStopTxOnInvalidId = {{"TxCtrlr"}, {"StopTxOnInvalidId"}};
    const ComponentVariable TxCtrlrTxBeforeAcceptedEnabled = {{"TxCtrlr"}, {"TxBeforeAcceptedEnabled"}};
    const ComponentVariable TxCtrlrTxStartPoint = {{"TxCtrlr"}, {"TxStartPoint"}};
    const ComponentVariable TxCtrlrTxStopPoint = {{"TxCtrlr"}, {"TxStopPoint"}};

} // namespace ControllerComponentVariables
} // namespace v201
} // namespace ocpp

#endif // OCPP_V201_CONTROLLER_COMPONENT_VARIABLES_HPP