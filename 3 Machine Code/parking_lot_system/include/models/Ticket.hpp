#pragma once

#include <string>
#include <memory>
#include <chrono>
#include "Vehicle.hpp"
#include "ParkingSlot.hpp"

class Ticket {
private:


    std::string ticketId;
    std::chrono::system_clock::time_point entryTime;
    // ✅ 1. Ticket Needs a Stable Snapshot
    // ✅ 2. ParkingSlot and Ticket have different ownership
    // ✅ 3. Loose Coupling Is Good
    std::shared_ptr<Vehicle> vehicle;
    std::shared_ptr<ParkingSlot> parkingSlot;
    int entryGateId;

public:
    Ticket(const std::string &id, std::shared_ptr<Vehicle> vechicle, std::shared_ptr<ParkingSlot> parkingSlot, int gateId);

    std::string getTicketId() const;
    std::chrono::system_clock::time_point getEntryTime() const;
    std::shared_ptr<Vehicle> getVechicle() const;
    std::shared_ptr<ParkingSlot> getParkingSlot() const;
    int getEntryGateId() const;

};