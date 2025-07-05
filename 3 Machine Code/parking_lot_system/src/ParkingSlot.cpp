#include "models/ParkingSlot.hpp"

ParkingSlot::ParkingSlot(int id, SlotType type)
    : id(id), type(type), occupied(false), parkedVehicle(nullptr) {}

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