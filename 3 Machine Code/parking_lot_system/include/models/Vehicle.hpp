#pragma once
#include <string>
#include "enums/VehicleType.hpp"

class Vehicle {
private:
    std::string vehicleNumber;
    VehicleType type;
public:
    Vehicle(const std::string& vehicleNumber, VehicleType type);

    std::string getVehicleNumber() const;
    VehicleType getType() const;
};