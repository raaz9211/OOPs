
#include <iostream>

#include "services/NearestSlotStrategy.hpp"

std::shared_ptr<ParkingSlot> NearestSlotStrategy::getAvailableSlot(
    const ParkingLot &lot,
    const std::shared_ptr<Vehicle> &vehicle)
{
    SlotType desiredType = ParkingSlot::getSlotTypeForVehicle(vehicle->getType());

    for (const auto& floor : lot.getFloors()){
        auto slot = floor->getNextAvailableSlot(desiredType);
        if(slot) {
            std::cout << slot.get()->getId();
            return slot;
        }
    }

    return nullptr;
}