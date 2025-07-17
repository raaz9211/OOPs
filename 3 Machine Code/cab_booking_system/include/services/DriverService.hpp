#pragma once

#include <unordered_map>
#include <vector>
#include <memory>

#include "../models/Driver.hpp"
#include "../models/Location.hpp"
#include "../services/DriverLocationService.hpp"


class DriverService {
private:
    std::shared_ptr<DriverLocationService> locationService;
    std::unordered_map<std::string, std::shared_ptr<Driver>> drivers;

public:
    DriverService(std::shared_ptr<DriverLocationService> locationService);
    void updateLocation(const std::string driverId, const Location &location);
    std::vector<std::shared_ptr<Driver>> getNearbyAvailableDrivers(const Location& riderLocation, double radiusKm = 5.0);
    void markDriverUnavailable(const std::string& driverId);
    void markDriverAvailable(const std::string& driverId);
    std::shared_ptr<Driver> getDriver(const std::string& driverId);
    void registerDriver(const std::string& driverId,
                const std::string& name,
                const std::string& cabNumber,
                const Location& initialLocation);
};