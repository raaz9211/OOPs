#pragma once
#include "../dto/trip_metadata.hpp"

class PricingStrategy {
public:
    virtual double calculatePrice(TripMetaData *tripMetaData) = 0;
};