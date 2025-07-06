#pragma once

#include <unordered_map>
#include <memory>
#include "models/ParkingFloor.hpp"

class ParkingLot {
private:
    std::unordered_map<int, std::shared_ptr<ParkingFloor>> floors;
public:
    void addFloor(std::shared_ptr<ParkingFloor> floor);

    // Coordinates across all floors
    std::shared_ptr<ParkingSlot> getNextAvailableSlot(SlotType type) const;
    std::vector<std::shared_ptr<ParkingSlot>> getAllAvailableSlots(SlotType type) const;

    std::shared_ptr<ParkingFloor> getFloor(int floorNumber) const;
    std::vector<std::shared_ptr<ParkingFloor>> getFloors() const;
};