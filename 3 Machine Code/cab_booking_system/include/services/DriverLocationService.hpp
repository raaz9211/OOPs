#pragma once

#include <unordered_map>
#include <vector>
#include <memory>

#include "../models/Driver.hpp"
#include "../models/Location.hpp"


class DriverLocationService {
private:
    std::unordered_map<std::string, Location> locationMap;
public:
    void updateLocation(const std::string driverId, const Location &location);
    Location getLocation(const std::string& driverId) const;
    std::vector<std::string> getDriversNearby(const Location& riderLocation, double radiusKm = 5.0) const;

};