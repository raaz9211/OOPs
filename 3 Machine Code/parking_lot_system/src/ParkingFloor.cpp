#include "models/ParkingFloor.hpp"


ParkingFloor::ParkingFloor(int floorNumber) : floorNumber(floorNumber) {}

int ParkingFloor::getFloorNumber() const {
    return floorNumber;
}

void ParkingFloor::addSlot(std::shared_ptr<ParkingSlot> slot) {
    slotsByType[slot->getType()].push_back(slot);
}


std::shared_ptr<ParkingSlot> ParkingFloor::getNextAvailableSlot(SlotType type) {
    auto &slots = slotsByType[type];
    for (const auto &slot : slots) {
        if (!slot->isOccupied()) {
            return slot;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<ParkingSlot>> ParkingFloor::getAvailableSlots(SlotType type) const {
    std::vector<std::shared_ptr<ParkingSlot>> availableSlots;
    auto slots = slotsByType.find(type);

    if(slots != slotsByType.end()) {
        for (const auto &slot : slots->second) {
            if(!slot->isOccupied()) {
                availableSlots.push_back(slot);
            }
        }
    }

    return availableSlots;

}