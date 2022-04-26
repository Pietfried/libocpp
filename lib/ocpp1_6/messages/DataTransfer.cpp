// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2022 Pionix GmbH and Contributors to EVerest

#include <ostream>
#include <string>

#include <boost/optional/optional.hpp>
#include <nlohmann/json.hpp>

#include <ocpp1_6/enums.hpp>
#include <ocpp1_6/messages/DataTransfer.hpp>
#include <ocpp1_6/ocpp_types.hpp>
#include <ocpp1_6/types.hpp>

using json = nlohmann::json;

namespace ocpp1_6 {

std::string DataTransferRequest::get_type() const {
    return "DataTransfer";
}

void to_json(json& j, const DataTransferRequest& k) {
    // the required parts of the message
    j = json{
        {"vendorId", k.vendorId},
    };
    // the optional parts of the message
    if (k.messageId) {
        j["messageId"] = k.messageId.value();
    }
    if (k.data) {
        j["data"] = k.data.value();
    }
}

void from_json(const json& j, DataTransferRequest& k) {
    // the required parts of the message
    k.vendorId = j.at("vendorId");

    // the optional parts of the message
    if (j.contains("messageId")) {
        k.messageId.emplace(j.at("messageId"));
    }
    if (j.contains("data")) {
        k.data.emplace(j.at("data"));
    }
}

/// \brief Writes the string representation of the given DataTransferRequest \p k to the given output stream \p os
/// \returns an output stream with the DataTransferRequest written to
std::ostream& operator<<(std::ostream& os, const DataTransferRequest& k) {
    os << json(k).dump(4);
    return os;
}

std::string DataTransferResponse::get_type() const {
    return "DataTransferResponse";
}

void to_json(json& j, const DataTransferResponse& k) {
    // the required parts of the message
    j = json{
        {"status", conversions::data_transfer_status_to_string(k.status)},
    };
    // the optional parts of the message
    if (k.data) {
        j["data"] = k.data.value();
    }
}

void from_json(const json& j, DataTransferResponse& k) {
    // the required parts of the message
    k.status = conversions::string_to_data_transfer_status(j.at("status"));

    // the optional parts of the message
    if (j.contains("data")) {
        k.data.emplace(j.at("data"));
    }
}

/// \brief Writes the string representation of the given DataTransferResponse \p k to the given output stream \p os
/// \returns an output stream with the DataTransferResponse written to
std::ostream& operator<<(std::ostream& os, const DataTransferResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace ocpp1_6