#pragma once

#include "rider_manager.hpp"
#include "driver_manager.hpp"
#include "../dto/trip_metadata.hpp"
#include "trip.hpp"
#include "strategy_manager.hpp"

class TripManager {
    RiderManager *riderManager;
    DriverManager *driverManager;
    unordered_map<int, TripMetaData*> tripsMetaDataInfo;
    unordered_map<int, Trip*> tripsInfo;
    TripManager() {
        riderManager = &RiderManager::getRiderManager();
        driverManager = &DriverManager::getDriverManager();
    }
public:
 static TripManager &getTripManager();
 void CreateTrip(Rider *rider, Location *srcLoc, Location *dstLoc);
 unordered_map<int, Trip*> getTripsMap();
};
