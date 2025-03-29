#include "strategy_manager.hpp"


StrategyManager &StrategyManager::getStrategyManager(){
    static StrategyManager strategyManager;
    return strategyManager;
}

PricingStrategy *StrategyManager::determinePricingStrategy(TripMetaData *tripMetaData) {
    cout << "Based on location and other factors, setting pricing strategy";
    return new RatingBasedPricingStratgy();
}


DriverMatchingStrategy *StrategyManager::determineMatchingStrategy(TripMetaData *tripMetaData){
    cout << "Based on location and other factors, setting matching strategy";
    return new LeastTimeBasedMatchingStrategy();
}
