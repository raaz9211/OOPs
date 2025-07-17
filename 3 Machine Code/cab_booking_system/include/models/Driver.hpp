#pragma once

#include <memory>

#include "User.hpp"
#include "Cab.hpp"


class Driver : public User {
private:
    std::shared_ptr<Cab> cab;
public:

    Driver(const std::string &id, const std::string &name, std::shared_ptr<Cab> &cab);

    std::shared_ptr<Cab> &getCab();
    std::shared_ptr<const Cab> getCab() const;
};