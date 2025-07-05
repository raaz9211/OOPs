#pragma once

#include "FeeCalculationStrategy.hpp"

class FlatRateFeeStrategy : public FeeCalculationStrategy {
private:
    double flatRate;
public:
    FlatRateFeeStrategy(double rate);
    virtual double calculateFee(std::chrono::system_clock::time_point entryTime,
        std::chrono::system_clock::time_point exitTime) override;

};