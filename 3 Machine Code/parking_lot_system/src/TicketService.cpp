#include "services/TicketService.hpp"

std::string TicketService::generateTicketId() {
    return "T-" + std::to_string(++ticketCounter);
}

std::shared_ptr<Ticket> TicketService::generateTicket(
        std::shared_ptr<Vehicle> vehicle,
        std::shared_ptr<ParkingSlot> slot,
        int entryGateId){
    std::string tickeId = generateTicketId();
    return std::make_shared<Ticket>(tickeId, vehicle, slot, entryGateId);
}