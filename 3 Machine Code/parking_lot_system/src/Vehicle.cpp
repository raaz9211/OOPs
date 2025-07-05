#include "models/Vehicle.hpp"

Vehicle::Vehicle(const std::string &number, VehicleType type)
    : vehicleNumber(number), type(type) {}

std::string Vehicle::getVehicleNumber() const
{
    return vehicleNumber;
}

VehicleType Vehicle::getType() const
{
    return type;
}
