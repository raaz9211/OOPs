#ifndef VEHICLE_SERVICE_H
#define VEHICLE_SERVICE_H

#include "../database/database.h"

class VehicleService {
private:
    Database &database = Database::getDatabase();
public:
    bool addVehicle(std::string username, std::string vehicle_name, std::string vehicle_no);
};

#endif // VEHICLE_SERVICE_H