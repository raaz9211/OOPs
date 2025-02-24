#include <iostream>
#include <algorithm>

#include "ride_UI.h"



void RideUI::ride_CLI(){

    std::string username;
    std::string sex;
    int age;

    std::string vehicle_name;
    std::string vehicle_no;

    std::string origin;
    int available_seats;
    int current_need;

    std::string destination;
    std::string selection_strategy;

    while (true)
    {
        std::cout << "Choose option \n";
        std::cout << " 1. Add user \n";
        std::cout << " 2. Add vehicle \n";
        std::cout << " 3. Add ride \n";
        std::cout << " 4. Show ride \n";
        std::cout << " 5. Show ride stats \n";
        std::cout << " 0. Exit \n";
        
        int option;
        std::cin >> option;

        switch (option)
        {
        case 0:
            exit(0);
            break;
        case 1:
            std::cout << "Enter username\n";
            std::cin >> username;
            std::cout << "Enter sex\n";
            std::cin >> sex;
            std::cout << "Enter age\n";
            std::cin >> age;
            RideUI::userService.addUser(username, sex, age);
            break;
        case 2:
            std::cout << "Enter username\n";
            std::cin >> username;
            std::cout << "Enter vehicle name\n";
            std::cin >> vehicle_name;
            std::cout << "Enter vehicle no.\n";
            std::cin >> vehicle_no;
            RideUI::vehicleService.addVehicle(username, vehicle_name, vehicle_no);
            break;
        case 3:
            std::cout << "Enter username\n";
            std::cin >> username;
            std::cout << "Enter vehicle name\n";
            std::cin >> vehicle_name;
            std::cout << "Enter vehicle no.\n";
            std::cin >> vehicle_no;
            std::cout << "Enter origin\n";
            std::cin >> origin;
            std::cout << "Enter available seats\n";
            std::cin >> available_seats;
            std::cout << "Enter destination\n";
            std::cin >> destination;
            RideUI::rideService.addRide(username, vehicle_name, vehicle_no, origin, available_seats, destination);
            break;
        case 4: 
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter origin: ";
            std::cin >> origin;
            std::cout << "Enter need seats: ";
            std::cin >> current_need;
            std::cout << "Enter destination: ";
            std::cin >> destination;
            std::cout << "Enter selection strategy: ";
            std::cin >> selection_strategy;
            RideUI::rideService.findRide(username, origin, current_need, destination, selection_strategy);
            break;
        case 5:
            RideUI::rideService.printRideStats();
            break;
        case -1:
            RideUI::database.printTable();
            break;
        default:
            break;
        }


    }

}
