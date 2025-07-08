#include "services/VehicleFactory.hpp"


std::shared_ptr<Vehicle> VehicleFactory::createVehicle(const std::string& licensePlate, VehicleType type) {
    return std::make_shared<Vehicle>(licensePlate, type);
}