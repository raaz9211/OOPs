#pragma once

#include <memory>

#include "models/Rider.hpp"
#include "models/Driver.hpp"

class MatchingStrategy {
public:
    virtual std::shared_ptr<Driver> matchDriver(const std::shared_ptr<Rider> &rider) = 0;
    virtual ~MatchingStrategy() = default;
};