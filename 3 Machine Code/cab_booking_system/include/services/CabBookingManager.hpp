#pragma once

#include <memory>
#include <string>

#include "services/CabBookingManager.hpp"
#include "services/RiderService.hpp"
#include "services/DriverService.hpp"
#include "services/MatchingEngine.hpp"
#include "services/NearestDriverStrategy.hpp"
#include "services/DriverLocationService.hpp"
#include "services/DefaultPricingStrategy.hpp"
#include "services/RideService.hpp"
#include "services/RatingSystem.hpp"

class CabBookingManager{
public:

    std::shared_ptr<RiderService> riderService;
    std::shared_ptr<DriverService> driverService;
    std::shared_ptr<MatchingEngine> matchingEngine;
    std::shared_ptr<PricingStrategy> pricingStrategy;
    std::shared_ptr<RideService> rideService;
    std::shared_ptr<RatingSystem> ratingSystem;

    CabBookingManager();
public:
    CabBookingManager(const CabBookingManager&) = delete;
    CabBookingManager& operator=(const CabBookingManager&) = delete;
    static std::shared_ptr<CabBookingManager> getInstance();

    std::shared_ptr<Ride> createRide(const std::string& riderId, const Location& drop);
    void initialize();

    void startRide(const std::string& riderId);
    void endRide(const std::string& riderId);
    void cancelRide(const std::string& riderId);
    void rateDriver(const std::string& fromRiderId, const std::string& toDriverId, double rating);
    void rateRider(const std::string& fromDriverId, const std::string& toRiderId, double rating);
    double getRating(const std::string& userId);
};
