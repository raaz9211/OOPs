#include "models/Cab.hpp"

Cab::Cab(const std::string &id, const Location &location) 
: cabId(id), currentLocation(location) {}

void Cab::updateLcoation(const Location &location) {
    currentLocation = location;
}

void Cab::setAvailability(bool available) {
    isAvailable = available;
}

bool Cab::available() const {
    return isAvailable;
}

const Location &Cab::getLocation() const {
    return currentLocation;
}

std::string Cab::getId() const {
    return cabId;
}