#include "services/DefaultPricingStrategy.hpp"

// #include <iostream>

DefaultPricingStrategy::DefaultPricingStrategy(double ratePerKm) : ratePerKm(ratePerKm) {}

double DefaultPricingStrategy::calculateFare(const std::shared_ptr<Ride> &ride) const {
    double distance = ride->getPickupLocation().distanceTo(ride->getDropLocation());
    // std::cout << ride->getPickupLocation().getLatitude();
    // std::cout << ride->getPickupLocation().getLongitude();
    // std::cout << ride->getDropLocation().getLatitude();
    // std::cout << ride->getDropLocation().getLongitude() << std::endl;


    return distance * ratePerKm;
}