#pragma once
#include "driver_matching_strategy.hpp"


class LeastTimeBasedMatchingStrategy : public DriverMatchingStrategy{
public:
    Driver *matchDriver(TripMetaData *tripMetaData) {
        DriverManager &driverManager = DriverManager::getDriverManager();

        if(driverManager.getDriverMap().size() == 0){
            cout << "No driver: What service is thos \n";
        }

        cout << "Using quadtree to see nearest cabs, using driover manger to get details of drivers";
        Driver *driver = driverManager.getDriverMap().begin()->second;
        cout << "Setting " << driver->getDriverName() << " as driver" << endl;
        tripMetaData->setDriverRating(driver->getRating());
        return driver;
    }
};