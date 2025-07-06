#pragma once

#include "FeeCalculationStrategy.hpp"

class HourlyFeeStrategy : public FeeCalculationStrategy
{
private:
    int ratePerHour;

public:
    HourlyFeeStrategy(int ratePerHour);
    virtual double calculateFee(std::chrono::system_clock::time_point entryTime,
                                std::chrono::system_clock::time_point exitTime) override;
};