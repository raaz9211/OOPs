#include "models/Driver.hpp"


Driver::Driver(const std::string &id, const std::string &name, std::shared_ptr<Cab> &cab)
        : User(id, name), cab(cab) {}


std::shared_ptr<Cab> &Driver::getCab() {
    return cab;
}

std::shared_ptr<const Cab> Driver::getCab() const {
    return cab;
}