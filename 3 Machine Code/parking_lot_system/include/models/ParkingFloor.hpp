#pragma once

#include <unordered_map>
#include <vector>
#include <memory>
#include "enums/SlotType.hpp"
#include "models/ParkingSlot.hpp"

class ParkingFloor {
private:
    int floorNumber;

    // Group slots by SlotType
    std::unordered_map<SlotType, std::vector<std::shared_ptr<ParkingSlot>>> slotsByType;
public:
    ParkingFloor(int floorNumber);

    int getFloorNumber() const;

    void addSlot(std::shared_ptr<ParkingSlot> slot);

    // Knows about the slots on its own floor
    std::shared_ptr<ParkingSlot> getNextAvailableSlot(SlotType type);
    std::vector<std::shared_ptr<ParkingSlot>> getAvailableSlots(SlotType type) const;
};