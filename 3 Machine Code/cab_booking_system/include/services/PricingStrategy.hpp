#pragma once

#include <memory>

#include "models/Ride.hpp"

class PricingStrategy {
public:
    virtual double calculateFare(const std::shared_ptr<Ride> &ride) const = 0;
    virtual ~PricingStrategy() = default;
};