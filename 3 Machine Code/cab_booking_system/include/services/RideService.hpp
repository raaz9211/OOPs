#pragma once

#include <unordered_map>
#include <memory>
#include <string>

#include "models/Ride.hpp"
#include "models/Rider.hpp"
#include "services/DriverService.hpp"
#include "services/MatchingEngine.hpp"
#include "services/PricingStrategy.hpp"

class RideService{
private:
    std::unordered_map<std::string, std::shared_ptr<Ride>> activeRides;

    std::shared_ptr<MatchingEngine> matchingEngine;
    std::shared_ptr<PricingStrategy> pricingStrategy;
    std::shared_ptr<DriverService> driverService;
public:
    RideService(std::shared_ptr<MatchingEngine> matchingEngine,
    std::shared_ptr<PricingStrategy> pricingStrategy,
    std::shared_ptr<DriverService> driverService);


    std::shared_ptr<Ride> createRide(const std::string &rideId,
                                    const std::shared_ptr<Rider> &rider,
                                    const Location &dropLocation);
                
    void startRide(const std::string& rideId);
    void endRide(const std::string &rideId);
    void cancelRide(const std::string &rideId);


};
