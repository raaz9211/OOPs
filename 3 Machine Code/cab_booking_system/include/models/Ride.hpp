#pragma once

#include <memory>

#include "Rider.hpp"
#include "Driver.hpp"
#include "Location.hpp"
#include "../enums/RideStatus.hpp"

class Ride {
private:
    std::string id;
    std::shared_ptr<Rider> rider;
    std::shared_ptr<Driver> driver;
    Location pickup;
    Location drop;
    RideStatus status;
    double fare;

public:
    Ride(std::string id,
    std::shared_ptr<Rider> rider,
    std::shared_ptr<Driver> driver,
    Location pickup,
    Location drop);

    std::shared_ptr<Rider> getRider() const;
    std::shared_ptr<Driver> getDriver() const;
    const Location& getPickupLocation() const;
    const Location& getDropLocation() const;
    RideStatus getStatus() const;
    double getFare() const;

    void startRide();
    void endRide(double fare);
    void cancelRide();
};