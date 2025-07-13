#include <cmath>

#include "models/Location.hpp"

Location::Location(double lat, double lon) : latitude(lat), longitude(lon) {}


double Location::getLatitude() const {
    return latitude;
}


double Location::getLongitude() const {
    return longitude;
}


double Location::distanceTo(const Location &tocation) const {
    double dx = this->latitude - latitude;
    double dy = this->longitude - longitude;

    return std::sqrt(dx * dx + dy * dy);
}