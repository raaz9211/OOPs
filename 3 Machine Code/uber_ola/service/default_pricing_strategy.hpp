#pragma once
#include "pricing_strategy.hpp"
#include "../common/common.hpp"


class DefaultPricingStrategy : public PricingStrategy {
public:
    double calculatePrice(TripMetaData *tripMetaData) {
        cout << "Based on default strategy, price is 100" << endl; 
        return 100.0;
    }
};