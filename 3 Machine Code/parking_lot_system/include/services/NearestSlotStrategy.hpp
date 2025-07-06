#pragma once

#include "SlotAllocationStrategy.hpp"

class NearestSlotStrategy : public SlotAllocationStrategy {
public:
    std::shared_ptr<ParkingSlot> getAvailableSlot(
        const ParkingLot& lot,
        const std::shared_ptr<Vehicle>& vehicle) override;
};