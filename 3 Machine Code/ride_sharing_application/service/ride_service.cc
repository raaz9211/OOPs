#include <iostream>
#include <algorithm>
#include<unordered_map>

#include "ride_service.h"
#include "../entity/ride.h"
#include "filter_ride_context.h"
#include "most_vacant_filter_ride.h"
#include "preferred_vehicle_filter_ride.h"

std::string _toLowerCase(std::string &s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::tolower(c); });
    return s;
}

bool RideService::addRide(std::string username,
                          std::string vehicle_name,
                          std::string vehicle_no,
                          std::string origin,
                          int available_seats,
                          std::string destination)
{
    if (RideService::database.table.count(username) == 0)
    {
        std::cout << "Add " << username << "first as user" << std::endl;
        return false;
    }
    std::vector<Vehicle *> *vehicles = &RideService::database.table[username].second;

    Ride *ride = new Ride();
    ride->setUsername(username);
    ride->setVehicleName(vehicle_name);
    ride->setVehicleNo(vehicle_no);
    ride->setOrigin(origin);
    ride->setAvailableSeats(available_seats);
    ride->setDestination(destination);
    ride->setBookedUsername({});

    Vehicle *matched_vehicle = NULL;

    for (auto *vehicle : *vehicles)
    {
        if (vehicle->getVehicleName() == vehicle_name and vehicle->getVehicleNo() == vehicle_no)
        {
            matched_vehicle = vehicle;
        }
    }

    if (matched_vehicle == NULL)
    {
        std::cout << "No matching vehicle found." << std::endl;
        return false;
    }
    matched_vehicle->addRides(ride);

    return true;
}


bool RideService::updateRide(Ride *ride, int current_need, std::string username)
{
    ride->setAvailableSeats(ride->getAvailableSeats() - current_need);
    ride->addBookedUsername(username);
    return true;
}

bool RideService::findRide(std::string username, std::string origin, int current_need, std::string destination, std::string selection_strategy)
{
    Ride *found_ride;

    FilterRideContext *context;
    if (selection_strategy == "Most Vacant")
    {
        MostVacantFilterRide mostVacantFilterRide;
        context = new FilterRideContext(&mostVacantFilterRide);
        found_ride = context->executeFilter(origin, current_need, destination);
    }
    PreferredVehicleFilterRide preferredVehicleFilterRide(selection_strategy);
    context->setStrategy(&preferredVehicleFilterRide);

    found_ride = context->executeFilter(origin, current_need, destination);
    if(found_ride){
        std::cout << "Origin: " << found_ride->getOrigin()
        << ", Destination: " << found_ride->getDestination()
        << ", Available Seats: " << found_ride->getAvailableSeats() << "\n";
        std::string get_response;
        std::cout << "Enter Yes to book\n";
        std::cin >> get_response;
        if(_toLowerCase(get_response) == "yes"){
            updateRide(found_ride, current_need, username);
            return true;
        }
    }

    std::cout << "Ride not found\n";
    return false;
}


void RideService::printRideStats(){
    std::unordered_map<std::string, std::pair<int, int>> ride_stats;
    for (const auto& entry :RideService::database.table) {
        const std::string& key = entry.first;
        const User* user = entry.second.first;
        const std::vector<Vehicle*>& vehicles = entry.second.second;
        
        for (const Vehicle* vehicle : vehicles) {
            if (vehicle) {
                for (const Ride* ride : vehicle->getRides()) {
                    if (ride) {
                        ride_stats[ride->getUsername()].first++;
                        for(std::string booked_username : ride->getBookedUsername()){
                            ride_stats[booked_username].second++;
                        }
                    }
                }
            } 
        }

        for(auto ride_stat : ride_stats){
            std::cout << "Username : " << ride_stat.first << " Offered : " << ride_stat.second.first << " Taken : " << ride_stat.second.second << std::endl;
        }
    }
}
