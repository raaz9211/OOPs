#include "models/Ride.hpp"


Ride::Ride(std::string id,
std::shared_ptr<Rider> rider,
std::shared_ptr<Driver> driver,
Location pickup,
Location drop) : id(id), rider(rider), driver(driver), pickup(pickup), drop(drop) {}


std::shared_ptr<Rider> Ride::getRider() const {
    return rider;
}

std::shared_ptr<Driver> Ride::getDriver() const {
    return driver;
}

const Location &Ride::getPickupLocation() const {
    return pickup;
}

const Location &Ride::getDropLocation() const {
    return drop;
}
RideStatus Ride::getStatus() const {
    return status;
}

double Ride::getFare() const {
    return fare;
}

void Ride::startRide() {
    status = RideStatus::ONGOING;
    driver->getCab()->setAvailability(false);
}

void Ride::endRide(double fare) {
    status = RideStatus::ONGOING;
    this->fare = fare;
    driver->getCab()->setAvailability(true);
}

void Ride::cancelRide() {
    status = RideStatus::CANCELLED;
    driver->getCab()->setAvailability(true);
}