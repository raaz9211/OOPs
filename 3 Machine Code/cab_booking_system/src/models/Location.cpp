#include <cmath>
// #include <iostream>

#include "models/Location.hpp"

Location::Location(double lat, double lon) : latitude(lat), longitude(lon) {}


double Location::getLatitude() const {
    return latitude;
}


double Location::getLongitude() const {
    return longitude;
}


double Location::distanceTo(const Location &location) const {
    double dx = this->latitude - location.getLatitude();
    double dy = this->longitude - location.getLongitude();

    // std::cout << dx << dy;

    return std::sqrt(dx * dx + dy * dy);
}