// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2023 Pionix GmbH and Contributors to EVerest

#include <utility>

#include <everest/logging.hpp>
#include <ocpp/v201/connector.hpp>

namespace ocpp {
namespace v201 {

namespace conversions {

std::string connector_event_to_string(ConnectorEvent e) {
    switch (e) {
    case ConnectorEvent::PlugIn:
        return "PlugIn";
    case ConnectorEvent::PlugOut:
        return "PlugOut";
    case ConnectorEvent::Reserve:
        return "Reserve";
    case ConnectorEvent::ReservationCleared:
        return "ReservationCleared";
    case ConnectorEvent::Error:
        return "Error";
    case ConnectorEvent::ErrorCleared:
        return "ErrorCleared";
    case ConnectorEvent::Enable:
        return "Enabled";
    case ConnectorEvent::Disable:
        return "Disabled";
    }

    throw std::out_of_range("No known string conversion for provided enum of type ConnectorEvent");
}

} // namespace conversions

Connector::Connector(const int32_t connector_id,
                     const std::function<void(const ConnectorStatusEnum& status)>& status_notification_callback) :
    connector_id(connector_id),
    // TODO verify init BEGIN
    enabled(true),
    reserved(false),
    plugged_in(false),
    faulted(false),
    effective_status(ConnectorStatusEnum::Available),
    // TODO verify init END
    status_notification_callback(status_notification_callback) {
}

ConnectorStatusEnum Connector::determine_effective_status(OperationalStatusEnum evse_status) {
    std::lock_guard<std::recursive_mutex> lg(this->state_mutex);
    if (evse_status != OperationalStatusEnum::Operative) {
        return ConnectorStatusEnum::Unavailable;
    }
    if (!this->enabled) {
        return ConnectorStatusEnum::Unavailable;
    }
    if (this->faulted) {
        return ConnectorStatusEnum::Faulted;
    }
    if (this->plugged_in) {
        return ConnectorStatusEnum::Occupied;
    }
    if (this->reserved) {
        return ConnectorStatusEnum::Reserved;
    }
    return ConnectorStatusEnum::Available;
}

void Connector::submit_event(ConnectorEvent event, OperationalStatusEnum evse_status) {
    std::lock_guard<std::recursive_mutex> lg(this->state_mutex);
    ConnectorStatusEnum prev_effective_state = this->determine_effective_status(evse_status);
    switch(event) {
    case ConnectorEvent::Enable:
        this->enabled = true;
        break;
    case ConnectorEvent::Disable:
        this->enabled = false;
        break;
    case ConnectorEvent::PlugIn:
        this->plugged_in = true;
        break;
    case ConnectorEvent::PlugOut:
        this->plugged_in = false;
        break;
    case ConnectorEvent::Reserve:
        this->reserved = true;
        break;
    case ConnectorEvent::ReservationCleared:
        this->reserved = false;
        break;
    case ConnectorEvent::Error:
        this->faulted = true;
        break;
    case ConnectorEvent::ErrorCleared:
        this->faulted = false;
        break;
    }
    // TODO persist the new state if needed
    // Recompute the effective state of the connector
    this->effective_status = this->determine_effective_status(evse_status);
    if (prev_effective_state != this->effective_status) {
        this->status_notification_callback(this->effective_status);
    }
}
ConnectorStatusEnum Connector::get_effective_status() {
    std::lock_guard<std::recursive_mutex> lg(this->state_mutex);
    return this->effective_status;
}

} // namespace v201
} // namespace ocpp
