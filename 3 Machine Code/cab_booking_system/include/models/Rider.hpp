#pragma once

#include "User.hpp"
#include "Location.hpp"


class Rider : public User {
private:
    Location currentLocation;

public:
    Rider(const std::string &id, const std::string &name, const Location& location);


    const Location& getCurrentLocation() const;
    void updateLocation(const Location& location);
};