#ifndef BOOK_H
#define BOOK_H

#include <string>

class Ride{
private:
    std::string username;
    std::string vehicle_name;
    std::string vehicle_no;
    std::string origin;
    int available_seats;
    std::string destination;
public:
  // Setters
  void setUsername(const std::string username) { this->username = username; }
  void setVehicleName(const std::string vehicle_name) { this->vehicle_name = vehicle_name; }
  void setVehicleNo(const std::string vehicle_no) { this->vehicle_no = vehicle_no; }
  void setOrigin(const std::string origin) { this->origin = origin; }
  void setDestination(const std::string destination) { this->destination = destination; }
  void setAvailableSeats(const int available_seats) { this->available_seats = available_seats; }

  // Getters
  std::string getUsername() const { return username; }
  std::string getVehicleName() const { return vehicle_name; }
  std::string getVehicleNo() const { return vehicle_no; }
  std::string getOrigin() const { return origin; }
  std::string getDestination() const { return destination; }
  int getAvailableSeats() const { return available_seats; }

};


#endif // BOOK_H