
#include "services/MatchingEngine.hpp"

MatchingEngine::MatchingEngine(std::shared_ptr<MatchingStrategy> strategy) 
    : strategy(strategy) {}

void MatchingEngine::setStrategy(std::shared_ptr<MatchingStrategy> newStrategy) {
    strategy = newStrategy;
}

std::shared_ptr<Driver> MatchingEngine::findDriverForRider(const std::shared_ptr<Rider> &rider) {
    return strategy ? strategy->matchDriver(rider) : nullptr;
}