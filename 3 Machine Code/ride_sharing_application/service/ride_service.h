#ifndef RIDE_SERVICE
#define RIDE_SERVICE

#include <vector>

#include "../entity/ride.h"
#include "../database/database.h"

class RideService
{
    Database &database = Database::getDatabase();

public:
    bool addRide(std::string username,
                 std::string vehicle_name,
                 std::string vehicle_no,
                 std::string origin,
                 int available_seats,
                 std::string destination);

    bool findRide(std::string username, std::string origin, int available_seats, std::string destination, std::string selection_strategy);
    bool updateRide(Ride *ride, int current_need, std::string username);
    void printRideStats();
};
#endif // RIDE_SERVICE
