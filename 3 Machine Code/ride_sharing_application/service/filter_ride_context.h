#ifndef FILTER_RIDE_CONTEXT_H
#define FILTER_RIDE_CONTEXT_H

#include "filter_ride.h"


class FilterRideContext {
private:
    FilterRide *filterRide;
public:
    FilterRideContext(FilterRide *filterRide) : filterRide(filterRide) {};

    void setStrategy(FilterRide *filterRide){
        this->filterRide = filterRide;
    }

    Ride *executeFilter(std::string origin, int available_seats, std::string destination){
        return filterRide->filterRide(origin, available_seats, destination);
    }
};

#endif // FILTER_RIDE_CONTEXT_H