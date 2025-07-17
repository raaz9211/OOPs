#pragma once

class Location {
private:
    double latitude;
    double longitude;

public:
    Location() : latitude(0.0), longitude(0.0) {}
    Location(double lat, double lon);
    double getLatitude() const;
    double getLongitude() const;

    double distanceTo(const Location& other) const;
};