#include <cmath>

#include "services/HourlyFeeStrategy.hpp"

HourlyFeeStrategy::HourlyFeeStrategy(int ratePerHour) : ratePerHour(ratePerHour) {}

double HourlyFeeStrategy::calculateFee(std::chrono::system_clock::time_point entryTime,
                                       std::chrono::system_clock::time_point exitTime)
{

    auto duration = std::chrono::duration_cast<std::chrono::minutes>(exitTime - entryTime);
    double hours = std::ceil(duration.count() / 60.0);
    return ratePerHour * std::max(1.0, hours); // Minimum 1 hours
}