#pragma once

#include <memory>
#include <unordered_map>
#include <string>
#include "../models/Ticket.hpp"
#include "../models/Vehicle.hpp"
#include "../models/ParkingSlot.hpp"

class TicketService {
private:
    int ticketCounter = 0;
    std::unordered_map<std::string, std::shared_ptr<Ticket>> ticketStore;

    std::string generateTicketId();
public:
    std::shared_ptr<Ticket> generateTicket(
        std::shared_ptr<Vehicle> vehicle,
        std::shared_ptr<ParkingSlot> slot,
        int entryGateId);
    std::shared_ptr<Ticket> getTicket(const std::string& ticketId);  // ✅ NEW

};