#pragma once
#include "pricing_strategy.hpp"
#include "../common/common.hpp"


class RatingBasedPricingStratgy : public PricingStrategy{
public:
    double calculatePrice(TripMetaData *tripMetaData) {
        double price = Util::isHighRating(tripMetaData->getRiderRating()) ? 55.0 : 65;
        cout << "Based on " << Util::ratingToString(tripMetaData->getRiderRating()) 
        << " rider rating, price of the trip is " << price << endl; 
        return price;
    }
};