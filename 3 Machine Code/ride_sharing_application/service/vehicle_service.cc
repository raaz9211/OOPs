#include<iostream>
#include<vector>

#include "vehicle_service.h"
#include "../entity/vehicle.h"


bool VehicleService::addVehicle(std::string username, std::string vehicle_name, std::string vehicle_no){
    if(VehicleService::database.table.count(username) == 0){
        std::cout << "Add " << username << "first as user" << std::endl;
        return false;
    }else{
        Vehicle *vehicle = new Vehicle();
        vehicle->setUsername(username);
        vehicle->setVehicleName(vehicle_name);
        vehicle->setVehicleNo(vehicle_no);
        vehicle->setRides({});
        VehicleService::database.table[username].second.push_back(vehicle);
        return false;
    }
}

