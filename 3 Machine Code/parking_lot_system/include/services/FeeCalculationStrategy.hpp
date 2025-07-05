#pragma once

#include <chrono>

class FeeCalculationStrategy {
public:
    virtual double calculateFee(std::chrono::system_clock::time_point entryTime,
    std::chrono::system_clock::time_point exitTime) = 0;
    ~FeeCalculationStrategy() = default;
};
