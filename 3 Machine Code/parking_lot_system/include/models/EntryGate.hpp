#pragma once

#include <memory>

#include "Gate.hpp"
#include "../services/TicketService.hpp"
#include "../models/Vehicle.hpp"
#include "../models/ParkingSlot.hpp"

class EntryGate : public Gate {
private:
    std::shared_ptr<TicketService> ticketService;

public:
    EntryGate(int id,
            const std::string &name,
            std::shared_ptr<TicketService> ticketService);

    std::shared_ptr<Ticket> processVehicleEntry(
        const std::shared_ptr<Vehicle> &vehicle,
        const std::shared_ptr<ParkingSlot> &assignedSlot);
        
};