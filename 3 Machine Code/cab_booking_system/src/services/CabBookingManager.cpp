#include <stdexcept>

#include "services/CabBookingManager.hpp"
#include "models/Rating.hpp"


CabBookingManager::CabBookingManager(){
    std::shared_ptr<DriverLocationService> locationService = std::make_shared<DriverLocationService>();
    riderService = std::make_shared<RiderService>();
    driverService = std::make_shared<DriverService>(locationService);
    std::shared_ptr<NearestDriverStrategy>  strategy = std::make_shared<NearestDriverStrategy>(driverService);
    matchingEngine = std::make_shared<MatchingEngine>(strategy);
    pricingStrategy = std::make_shared<DefaultPricingStrategy>();
    rideService = std::make_shared<RideService>(matchingEngine, pricingStrategy, driverService);

    ratingSystem = std::make_shared<RatingSystem>();  // ✅ integrated

}

std::shared_ptr<CabBookingManager> CabBookingManager::getInstance() {
    static std::shared_ptr<CabBookingManager> instance = std::make_shared<CabBookingManager>();
    return instance;
}

void CabBookingManager::initialize() {

    // Register riders
    riderService->registerRider("r1", "Raj", Location(0, 0));
    riderService->registerRider("r2", "Arya", Location(5, 5));
    riderService->registerRider("r3", "Deepika", Location(10, 10));
    riderService->registerRider("r4", "Thakur", Location(10, 10));

    // Register drivers
    driverService->registerDriver("d1", "Driver One", "DL001", Location(1, 1));
    driverService->registerDriver("d2", "Driver Two", "DL002", Location(6, 6));
    driverService->registerDriver("d3", "Driver Three", "DL003", Location(13, 13));
    driverService->registerDriver("d4", "Driver Four", "DL004", Location(3, 3));
}

std::shared_ptr<Ride> CabBookingManager::createRide(const std::string& riderId, const Location& drop) {
    auto rider = riderService->getRiderById(riderId);
    if (!rider) {
        throw std::runtime_error("Rider not found.");
    }
    std::string rideId = "ride-" + riderId;  // simplistic unique ID
    return rideService->createRide(rideId, rider, drop);
}

void CabBookingManager::startRide(const std::string& riderId) {
    std::string rideId = "ride-" + riderId;
    rideService->startRide(rideId);
}

void CabBookingManager::endRide(const std::string& riderId) {
    std::string rideId = "ride-" + riderId;
    rideService->endRide(rideId);
}

void CabBookingManager::cancelRide(const std::string& riderId) {
    std::string rideId = "ride-" + riderId;
    rideService->cancelRide(rideId);
}

void CabBookingManager::rateDriver(const std::string& fromRiderId, const std::string& toDriverId, double rating) {
    ratingSystem->addRating(Rating(fromRiderId, toDriverId, rating));
}

void CabBookingManager::rateRider(const std::string& fromDriverId, const std::string& toRiderId, double rating) {
    ratingSystem->addRating(Rating(fromDriverId, toRiderId, rating));
}


double CabBookingManager::getRating(const std::string& userId) {
    return ratingSystem->getAverageRating(userId);
}
