#include <algorithm>

#include "services/NearestDriverStrategy.hpp"


NearestDriverStrategy::NearestDriverStrategy(std::shared_ptr<DriverService> driverService)
    : driverService(std::move(driverService)) {}


std::shared_ptr<Driver> NearestDriverStrategy::matchDriver(const std::shared_ptr<Rider> &rider) {
    auto riderLocation = rider->getCurrentLocation();
    auto drivers = driverService->getNearbyAvailableDrivers(riderLocation);
    std::vector<std::shared_ptr<Driver>>::iterator nearestIt = std::min_element(
        drivers.begin(),
        drivers.end(),
        [&riderLocation](const std::shared_ptr<Driver> &driver1, const std::shared_ptr<Driver> &driver2) {
            double dist1 = riderLocation.distanceTo(driver1->getCab()->getLocation());
            double dist2 = riderLocation.distanceTo(driver2->getCab()->getLocation());
            return dist1 < dist2;
        }
    );

    return nearestIt != drivers.end() ? *nearestIt : nullptr;
}