#include "models/ParkingFloor.hpp"


ParkingFloor::ParkingFloor(int floorNumber) : floorNumber(floorNumber), displayBoard(std::make_shared<DisplayBoard>(floorNumber)) {

}

int ParkingFloor::getFloorNumber() const {
    return floorNumber;
}

void ParkingFloor::addSlot(std::shared_ptr<ParkingSlot> slot) {
    slotsByType[slot->getType()].push_back(slot);
    updateDisplayBoard();
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

std::shared_ptr<DisplayBoard> ParkingFloor::getDisplayBoard() const {
    return displayBoard;
}

void ParkingFloor::updateDisplayBoard() {
    for (const auto& pair : slotsByType) {
        SlotType type = pair.first;
        int available = 0;
        for (const auto& slot : pair.second) {
            if (!slot->isOccupied()) ++available;
        }
        displayBoard->updateSlotAvailability(type, available);
    }
}