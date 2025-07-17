#include "services/DriverService.hpp"

// #include <iostream>

DriverService::DriverService(std::shared_ptr<DriverLocationService> locationService)
    : locationService(std::move(locationService)) {}

std::shared_ptr<Driver> DriverService::getDriver(const std::string& driverId) {
    auto it = drivers.find(driverId);
    return it != drivers.end() ? it->second : nullptr;
}

void DriverService::registerDriver(const std::string& driverId,
                const std::string& name,
                const std::string& cabNumber,
                const Location& initialLocation) {
    auto cab = std::make_shared<Cab>(cabNumber, initialLocation);
    auto driver = std::make_shared<Driver>(driverId, name, cab);
    driver->getCab()->setAvailability(true);        
    locationService->updateLocation(driverId, initialLocation);
    drivers[driverId] = driver;
}

void DriverService::updateLocation(const std::string driverId, const Location &location) {
    auto driver = getDriver(driverId);
        // std::cout<<driver->getId() << "ss";

    if (driver) {
        driver->getCab()->updateLcoation(location);
        locationService->updateLocation(driverId, location);
    }

}


std::vector<std::shared_ptr<Driver>> DriverService::getNearbyAvailableDrivers(const Location& riderLocation, double radiusKm) {
    std::vector<std::shared_ptr<Driver>> result;
    auto nearbyIds = locationService->getDriversNearby(riderLocation, radiusKm);
    // std::cout<<nearbyIds.size();
    for (const auto& id : nearbyIds) {
        auto driver = getDriver(id);
        if (driver && driver->getCab()->available()) {
            result.push_back(driver);
        }
    }
    return result;
}



void DriverService::markDriverUnavailable(const std::string& driverId) {
    auto driver = getDriver(driverId);
    if(driver){
        driver->getCab()->setAvailability(false);
    }
}

void DriverService::markDriverAvailable(const std::string& driverId) {
    auto driver = getDriver(driverId);
    if(driver){
        driver->getCab()->setAvailability(true);
    }
}


