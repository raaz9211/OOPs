#ifndef FILTER_RIDE_H
#define FILTER_RIDE_H

#include <iostream>
#include "../entity/ride.h"

// Abstract Strategy class
class FilterRide{
public:
    virtual Ride *filterRide(std::string origin, int available_seats, std::string destination) = 0; // Pure virtual function
    virtual ~FilterRide() = default;
};

#endif // FILTER_RIDE_H
