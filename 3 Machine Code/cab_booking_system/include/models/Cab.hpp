#pragma once

#include <string>

#include "models/Location.hpp"

class Cab {
private:
    std::string cabId;
    Location currentLocation;
    bool isAvailable;
public:
    Cab(const std::string &id, const Location &location);

    void updateLcoation(const Location &location);
    void setAvailability(bool available);

    bool available() const;
    const Location &getLocation() const;
    std::string getId() const;
};