#include "models/Ticket.hpp"

Ticket::Ticket(const std::string &id, std::shared_ptr<Vehicle> vehicle, std::shared_ptr<ParkingSlot> slot, int gateId) 
: ticketId(id), vehicle(vehicle), parkingSlot(slot), entryGateId(gateId), entryTime(std::chrono::system_clock::now()) {}


std::string Ticket::getTicketId() const {
    return ticketId;
}


std::chrono::system_clock::time_point Ticket::getEntryTime() const {
    return entryTime;
}

std::shared_ptr<Vehicle> Ticket::getVechicle() const {
    return vehicle;
}

std::shared_ptr<ParkingSlot> Ticket::getParkingSlot() const {
    return parkingSlot;
}

int Ticket::getEntryGateId() const {
    return entryGateId;
}