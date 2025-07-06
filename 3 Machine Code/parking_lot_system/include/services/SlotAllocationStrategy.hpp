#pragma once

#include <memory>

#include "../models/ParkingLot.hpp"
#include "../models/Vehicle.hpp"
#include "../models/ParkingSlot.hpp"

class SlotAllocationStrategy {
public:
    virtual std::shared_ptr<ParkingSlot> getAvailableSlot(
        const ParkingLot &lot,
        const std::shared_ptr<Vehicle> &vehicle) = 0;

    virtual ~SlotAllocationStrategy() = default;
};