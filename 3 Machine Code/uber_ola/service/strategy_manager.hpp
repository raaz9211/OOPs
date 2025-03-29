#pragma once

#include "../dto/trip_metadata.hpp"
#include "rating_based_pricing_strategy.hpp"
#include "default_pricing_strategy.hpp"
#include "least_time_based_matching_strategy.hpp"




class StrategyManager {
    StrategyManager() {}
    static StrategyManager strategyManager;
public:
    static StrategyManager &getStrategyManager();
    PricingStrategy *determinePricingStrategy(TripMetaData *tripMetaData);
    DriverMatchingStrategy *determineMatchingStrategy(TripMetaData *tripMetaData);
};
