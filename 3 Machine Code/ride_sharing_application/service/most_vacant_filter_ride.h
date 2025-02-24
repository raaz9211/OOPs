#ifndef MOST_PREFERRED_FILTER_RIDE_H
#define MOST_PREFERRED_FILTER_RIDE_H

#include <string>
#include "filter_ride.h"
#include "../database/database.h"
#include "../entity/ride.h"


// Abstract Strategy class
class MostVacantFilterRide : public FilterRide{
private:
std::string  preferred_vehicle;
Database &database = Database::getDatabase();

public:
    MostVacantFilterRide() {}
    Ride *filterRide(std::string origin, int available_seats, std::string destination){
        Ride *ride_found = NULL;
        int current_available_seats = 0;
        for(auto data : database.getDatabase().table){
            for(auto vehicle : data.second.second){
                for(auto ride : vehicle->getRides()){
                    if(ride->getOrigin() == origin 
                    and ride->getDestination() == destination 
                    and ride->getVehicleName() == preferred_vehicle
                    and ride->getAvailableSeats() >= available_seats){
                        if(ride->getAvailableSeats() > current_available_seats){
                            current_available_seats = ride->getAvailableSeats();
                            ride_found = ride;
                        }
                    }
                }
            }
        }
        return ride_found;
    }
};

#endif // MOST_PREFERRED_FILTER_RIDE_H
