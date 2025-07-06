#include "models/ParkingLot.hpp"

void ParkingLot::addFloor(std::shared_ptr<ParkingFloor> floor) {
    floors[floor->getFloorNumber()] = floor;
}

std::shared_ptr<ParkingSlot> ParkingLot::getNextAvailableSlot(SlotType type) const {
    for (const auto &[floorNo, floor] : floors) {
        auto slot = floor->getNextAvailableSlot(type);

        if(slot) {
            return slot;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<ParkingSlot>> ParkingLot::getAllAvailableSlots(SlotType type) const {
    std::vector<std::shared_ptr<ParkingSlot>>  availableParkingSlots;
    for (const auto &[floorNo, floor] : floors) {
        auto slots  = floor->getAvailableSlots(type);
        availableParkingSlots.insert(availableParkingSlots.end(), slots.begin(), slots.end());
    }
    return availableParkingSlots;
}

std::shared_ptr<ParkingFloor> ParkingLot::getFloor(int floorNumber) const {
    auto it = floors.find(floorNumber);
    if (it != floors.end()) {
        return it->second;
    }
    return nullptr;
}

std::vector<std::shared_ptr<ParkingFloor>> ParkingLot::getFloors() const {
    std::vector<std::shared_ptr<ParkingFloor>> result;
    for (const auto &[_, floor] : floors) {
        result.push_back(floor);
    }
    return result;
}