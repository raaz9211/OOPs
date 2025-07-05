#include "services/FlatRateFeeStrategy.hpp"

FlatRateFeeStrategy::FlatRateFeeStrategy(double rate) : flatRate(rate) {}

double FlatRateFeeStrategy::calculateFee(std::chrono::system_clock::time_point entryTime,
                                         std::chrono::system_clock::time_point exitTime)
{
    return flatRate;
}