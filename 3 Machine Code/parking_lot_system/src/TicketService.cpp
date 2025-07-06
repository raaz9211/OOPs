#include "services/TicketService.hpp"

std::string TicketService::generateTicketId() {
    return "T-" + std::to_string(++ticketCounter);
}

std::shared_ptr<Ticket> TicketService::generateTicket(
        std::shared_ptr<Vehicle> vehicle,
        std::shared_ptr<ParkingSlot> slot,
        int entryGateId){
    std::string tickeId = generateTicketId();
    auto ticket = std::make_shared<Ticket>(tickeId, vehicle, slot, entryGateId);
    ticketStore[tickeId] = ticket;
    return ticket;
}

std::shared_ptr<Ticket> TicketService::getTicket(const std::string& ticketId) {
    auto it = ticketStore.find(ticketId);
    if (it != ticketStore.end()) {
        return it->second;
    }
    return nullptr;
}