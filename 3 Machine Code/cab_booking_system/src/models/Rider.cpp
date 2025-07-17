#include "models/Rider.hpp"

Rider::Rider(const std::string &id, const std::string &name, const Location& location) 
: User(id, name), currentLocation(location) {}



const Location &Rider::getCurrentLocation() const {
    return currentLocation;
}

void Rider::updateLocation(const Location& location) {
    this->currentLocation = location;
}