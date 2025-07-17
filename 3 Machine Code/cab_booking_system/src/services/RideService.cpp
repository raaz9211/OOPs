#include <stdexcept>
// #include <iostream>

#include "services/RideService.hpp"


RideService::RideService(std::shared_ptr<MatchingEngine> matchingEngine,
    std::shared_ptr<PricingStrategy> pricingStrategy,
    std::shared_ptr<DriverService> driverService) 
    : matchingEngine(std::move(matchingEngine)), 
      pricingStrategy(std::move(pricingStrategy)),
      driverService(std::move(driverService)) {}



std::shared_ptr<Ride> RideService::createRide(const std::string &rideId,
    const std::shared_ptr<Rider> &rider,
    const Location &dropLocation) {

    std::shared_ptr<Driver> driver = matchingEngine->findDriverForRider(rider);
    
    if (!driver) {
        throw std::runtime_error("No available drivers found.");
    }

    driverService->updateLocation(driver->getId(), driver->getCab()->getLocation());
    driverService->markDriverUnavailable(driver->getId());


    std::shared_ptr<Ride> ride = std::make_shared<Ride>(rideId, rider, driver, rider->getCurrentLocation(), dropLocation);
    activeRides[rideId] = ride;

    return ride;
}
                
void RideService::startRide(const std::string& rideId) {
    auto it = activeRides.find(rideId);

    if(it == activeRides.end()) { 
        throw std::runtime_error("Ride ID not found.");
    }

    it->second->startRide();
}

void RideService::endRide(const std::string &rideId) {
    auto it = activeRides.find(rideId);

    if(it == activeRides.end()) { 
        throw std::runtime_error("Ride ID not found.");
    }

    auto ride = it->second;
    auto t = pricingStrategy->calculateFare(ride);
    // std::cout << t;
    ride->endRide(t);


    driverService->updateLocation(ride->getDriver()->getId(), ride->getDropLocation());
    driverService->markDriverAvailable(ride->getDriver()->getId());

    activeRides.erase(it);
}

void RideService::cancelRide(const std::string &rideId) {
    auto it = activeRides.find(rideId);

    if(it == activeRides.end()) { 
        throw std::runtime_error("Ride ID not found.");
    }
    auto ride = it->second;
    ride->cancelRide();

    driverService->markDriverAvailable(ride->getDriver()->getId());

    activeRides.erase(it);
}

