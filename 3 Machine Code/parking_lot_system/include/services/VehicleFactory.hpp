#pragma once

#include <memory>
#include <string>

#include "../models/Vehicle.hpp"
#include "../enums/VehicleType.hpp"

class VehicleFactory {
public:
    static std::shared_ptr<Vehicle> createVehicle( const std::string& licensePlate, VehicleType type);
};