#pragma once

#include "../entity/driver.hpp"
#include "../entity/rider.hpp"


//This class basically has all the info that will be used by strategy 
//Pricing strategy and Driver Matching strategy will need data
//Even if more data is needed, only this class needs to be updated

class TripMetaData {
    Location * srcLocation;
    Location * dstLocation;
    RATING riderRating;
    RATING driverRating;

public:
    TripMetaData(Location *srcLocation, Location *dstLocation, RATING riderRating) : 
    srcLocation(srcLocation), dstLocation(dstLocation), riderRating(riderRating), driverRating(RATING::UNASSIGNED) {}

    RATING getRiderRating() {
        return riderRating;
    }
    
    RATING getDriverRating() {
        return driverRating;
    }
    
    void setDriverRating(RATING driverRating) {
        this->driverRating = driverRating;
    }
};