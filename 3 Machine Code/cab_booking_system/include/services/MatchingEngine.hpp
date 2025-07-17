#pragma once

#include "MatchingStrategy.hpp"
#include "models/Rider.hpp"
#include "models/Driver.hpp"

#include <memory>

class MatchingEngine {
private:
    std::shared_ptr<MatchingStrategy> strategy;
public:
    MatchingEngine(std::shared_ptr<MatchingStrategy> strategy);

    void setStrategy(std::shared_ptr<MatchingStrategy> newStrategy);

    std::shared_ptr<Driver> findDriverForRider(const std::shared_ptr<Rider> &rider);
};