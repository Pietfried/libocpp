// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2023 Pionix GmbH and Contributors to EVerest

#include <ocpp/v16/enums.hpp>
#include <ocpp/v16/messages/FirmwareStatusNotification.hpp>

#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp::v16 {

std::string FirmwareStatusNotificationRequest::get_type() const {
    return "FirmwareStatusNotification";
}

void to_json(json& j, const FirmwareStatusNotificationRequest& k) {
    // the required parts of the message
    j = json{
        {"status", k.status.string()},
    };
    // the optional parts of the message
}

void from_json(const json& j, FirmwareStatusNotificationRequest& k) {
    // the required parts of the message
    k.status = FirmwareStatus(j.at("status"));

    // the optional parts of the message
}

/// \brief Writes the string representation of the given FirmwareStatusNotificationRequest \p k to the given output
/// stream \p os \returns an output stream with the FirmwareStatusNotificationRequest written to
std::ostream& operator<<(std::ostream& os, const FirmwareStatusNotificationRequest& k) {
    os << json(k).dump(4);
    return os;
}

std::string FirmwareStatusNotificationResponse::get_type() const {
    return "FirmwareStatusNotificationResponse";
}

void to_json(json& j, const FirmwareStatusNotificationResponse& k) {
    // the required parts of the message
    j = json({}, true);
    // the optional parts of the message
    (void)k; // no elements to unpack, silence unused parameter warning
}

void from_json(const json& j, FirmwareStatusNotificationResponse& k) {
    // the required parts of the message

    // the optional parts of the message
    // no elements to unpack, silence unused parameter warning
    (void)j;
    (void)k;
}

/// \brief Writes the string representation of the given FirmwareStatusNotificationResponse \p k to the given output
/// stream \p os \returns an output stream with the FirmwareStatusNotificationResponse written to
std::ostream& operator<<(std::ostream& os, const FirmwareStatusNotificationResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace ocpp::v16
