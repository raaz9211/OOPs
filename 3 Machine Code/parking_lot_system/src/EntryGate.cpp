#include "models/EntryGate.hpp"

EntryGate::EntryGate(int id,
                    const std::string &name,
                    std::shared_ptr<TicketService> ticketService) 
                    : Gate(id, name), ticketService(ticketService) {}


std::shared_ptr<Ticket> EntryGate::processVehicleEntry(const std::shared_ptr<Vehicle> &vehicle, const std::shared_ptr<ParkingSlot> &assignedSlot) {
    return ticketService->generateTicket(vehicle, assignedSlot, gateId);
}