#pragma once

#include <memory>

#include "MatchingStrategy.hpp"
#include "DriverService.hpp"

class NearestDriverStrategy : public MatchingStrategy {
private:
    std::shared_ptr<DriverService> driverService;
public:
    explicit NearestDriverStrategy(std::shared_ptr<DriverService> driverService);

    std::shared_ptr<Driver> matchDriver(const std::shared_ptr<Rider> &rider) override;
};