#ifndef RIDE_UI_H
#define RIDE_UI_H

#include "service/user_service.h"
#include "service/vehicle_service.h"
#include "service/ride_service.h"

#include "database/database.h"

class RideUI {
    Database &database = Database::getDatabase();
    UserService userService;
    VehicleService vehicleService;
    RideService rideService;


public:
    void ride_CLI();

};

#endif // RIDE_UI_H
