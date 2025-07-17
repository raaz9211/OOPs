#include <stdexcept>
// #include <iostream>

#include "services/DriverLocationService.hpp"

void DriverLocationService::updateLocation(const std::string driverId, const Location &location) {
    locationMap[driverId] = location;

}

Location DriverLocationService::getLocation(const std::string& driverId) const {
    auto it = locationMap.find(driverId);
    if (it != locationMap.end()) {
        return it->second;
    }

    throw std::runtime_error("Location not found.");
}


std::vector<std::string> DriverLocationService::getDriversNearby(const Location& riderLocation, double radiusKm) const {
    std::vector<std::string> nearbyDrivers;
    // std::cout << locationMap.size();
    for (const auto& [driverId, location] : locationMap) {
        if (riderLocation.distanceTo(location) <= radiusKm) {
            nearbyDrivers.push_back(driverId);
        }
    }
    return nearbyDrivers;
}
