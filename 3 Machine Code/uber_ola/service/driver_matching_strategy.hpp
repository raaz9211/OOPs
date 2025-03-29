#pragma once
#include "../dto/trip_metadata.hpp"
#include "driver_manager.hpp"


class DriverMatchingStrategy {
public:
    virtual Driver *matchDriver(TripMetaData *tripMetaData) = 0;
};