#include <stdexcept>

#include "models/ParkingSlot.hpp"

ParkingSlot::ParkingSlot(int id, SlotType type, int floorNumber)
    : id(id), type(type), occupied(false), parkedVehicle(nullptr), floorNumber(floorNumber) {}

int ParkingSlot::getId() const {
    return id;
}

SlotType ParkingSlot::getType() const {
    return type;
}

bool ParkingSlot::isOccupied() const {
    return occupied;
}

void ParkingSlot::assignVehicle(const std::shared_ptr<Vehicle>& vehicle) {
    parkedVehicle = vehicle;
    occupied = true;
}

void ParkingSlot::removeVehicle() {
    parkedVehicle.reset();
    occupied = false;
}

std::shared_ptr<Vehicle> ParkingSlot::getParkedVehicle() const {
    return parkedVehicle;
}


SlotType ParkingSlot::getSlotTypeForVehicle(VehicleType type) {
    switch (type) {
        case VehicleType::CAR:   return SlotType::CAR_SLOT;
        case VehicleType::BIKE:  return SlotType::BIKE_SLOT;
        case VehicleType::TRUCK: return SlotType::TRUCK_SLOT;
        case VehicleType::ELECTRIC:    return SlotType::ELECTRIC_SLOT;
        default: throw std::invalid_argument("Unknown VehicleType");

    }
}

int ParkingSlot::getFloorNumber() const {
    return floorNumber;
}