#pragma once

#include "PricingStrategy.hpp"

class DefaultPricingStrategy : public PricingStrategy{
private:
    double ratePerKm;
public:
    explicit DefaultPricingStrategy(double ratePerKm = 10.0);
    double calculateFare(const std::shared_ptr<Ride> &ride) const override;
};