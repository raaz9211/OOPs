#ifndef PREFERRED_VEHICLE_FILTER_RIDE_H
#define PREFERRED_VEHICLE_FILTER_RIDE_H

#include <string>
#include "filter_ride.h"
#include "../database/database.h"
#include "../entity/ride.h"


// Abstract Strategy class
class PreferredVehicleFilterRide : public FilterRide{
private:
std::string  preferred_vehicle;
Database &database = Database::getDatabase();

public:
    PreferredVehicleFilterRide(std::string  preferred_vehicle) : preferred_vehicle(preferred_vehicle) {}
    Ride *filterRide(std::string origin, int available_seats, std::string destination){
        for(auto data : database.getDatabase().table){
            for(auto vehicle : data.second.second){
                for(auto ride : vehicle->getRides()){
                    if(ride->getOrigin() == origin 
                    and ride->getDestination() == destination 
                    and ride->getVehicleName() == preferred_vehicle 
                    and ride->getAvailableSeats() >= available_seats){
                        return ride;
                    }
                }
            }
        }
        return NULL;
    }
};

#endif // PREFERRED_VEHICLE_FILTER_RIDE_H
