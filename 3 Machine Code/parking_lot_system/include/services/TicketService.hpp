#pragma once

#include <memory>
#include <string>
#include "../models/Ticket.hpp"
#include "../models/Vehicle.hpp"
#include "../models/ParkingSlot.hpp"

class TicketService {
private:
    int ticketCounter = 0;

    std::string generateTicketId();
public:
    std::shared_ptr<Ticket> generateTicket(
        std::shared_ptr<Vehicle> vehicle,
        std::shared_ptr<ParkingSlot> slot,
        int entryGateId);
};