#pragma once
#include <memory>
#include "enums/SlotType.hpp"
#include "models/Vehicle.hpp"

class ParkingSlot {
private:
    int id;
    SlotType type;
    bool occupied;
    std::shared_ptr<Vehicle> parkedVehicle;
public:
    ParkingSlot(int id, SlotType type);

    int getId() const;
    SlotType getType() const;
    bool isOccupied() const;
    
    void assignVehicle(const std::shared_ptr<Vehicle>& vehicle);
    void removeVehicle();
    std::shared_ptr<Vehicle> getParkedVehicle() const;

};