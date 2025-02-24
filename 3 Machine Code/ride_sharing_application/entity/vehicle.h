#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <vector>

#include "ride.h"


class Vehicle{
private:
    std::string username;
    std::string vehicle_name;
    std::string vehicle_no;
    std::vector<Ride*> rides;

public:
    void setUsername(std::string username){
        this->username = username;
    }

    void setVehicleName(std::string vehicle_name){
        this->vehicle_name = vehicle_name;
    }

    void setVehicleNo(std::string vehicle_no){
        this->vehicle_no = vehicle_no;
    }


    void setRides(std::vector<Ride*> rides){
        this->rides = rides;
    }

    void addRides(Ride* ride){
        this->rides.push_back(ride);
    }

    std::string getUsername() const {
        return this->username;
    }

    std::string getVehicleName() const {
        return this->vehicle_name;
    }

    std::string getVehicleNo() const {
        return  this->vehicle_no;
    }

    std::vector<Ride*> getRides() const {
        return  this->rides;
    }
 
};

#endif // VEHICLE_H