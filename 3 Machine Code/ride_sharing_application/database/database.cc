#include<unordered_map>
#include<string>
#include<vector>

#include "database.h"


Database  &Database::getDatabase(){
    static Database database;  // Thread-safe since C++11
    return database;
}

void Database::printTable() {
    for (const auto& entry : Database::table) {
        const std::string& key = entry.first;
        const User* user = entry.second.first;
        const std::vector<Vehicle*>& vehicles = entry.second.second;
        
        std::cout << "Key: " << key << "\n";
        if (user) {
            std::cout << "  User: " << user->getUsername() 
                      << ", Age: " << user->getAge()
                      << ", Sex: " << user->getSex() << "\n";
        } else {
            std::cout << "  User: nullptr\n";
        }
        
        std::cout << "  Vehicles: \n";
        for (const Vehicle* vehicle : vehicles) {
            if (vehicle) {
                std::cout << "    Model: " << vehicle->getVehicleName() 
                          << ", Number: " << vehicle->getVehicleNo()
                          << ", Owner: " << vehicle->getUsername() << "\n";
                
                std::cout << "    Rides: \n";
                // std::cout << vehicle->getRides().size();
                // break;
                for (const Ride* ride : vehicle->getRides()) {
                    if (ride) {
                        std::cout << "      Origin: " << ride->getOrigin()
                                  << ", Destination: " << ride->getDestination()
                                  << ", Available Seats: " << ride->getAvailableSeats() << "\n";
                    } else {
                        std::cout << "      nullptr\n";
                    }
                }
            } else {
                std::cout << "    nullptr\n";
            }
        }
    }
}