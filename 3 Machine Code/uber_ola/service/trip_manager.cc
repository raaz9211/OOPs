#include "trip_manager.hpp"


TripManager &TripManager::getTripManager(){
    static TripManager tripManager;
    return tripManager;
}
void TripManager::CreateTrip(Rider *rider, Location *srcLoc, Location *dstLoc) {
    TripMetaData *tripMetaData = new TripMetaData(srcLoc, dstLoc, rider->getRating());
    StrategyManager &strategyManager = StrategyManager::getStrategyManager();
    PricingStrategy *pricingStrategy = strategyManager.determinePricingStrategy(tripMetaData);
    DriverMatchingStrategy *driverMatchingStrategy = strategyManager.determineMatchingStrategy(tripMetaData);

    Driver *driver = driverMatchingStrategy->matchDriver(tripMetaData);
    double tripPrice = pricingStrategy->calculatePrice(tripMetaData);

    Trip *trip = new Trip(rider, driver, srcLoc, dstLoc, tripPrice, pricingStrategy, driverMatchingStrategy);
    int tripId = trip->getTripId();
    tripsInfo[tripId] = trip;
    tripsMetaDataInfo[tripId] = tripMetaData;

}
unordered_map<int, Trip*> TripManager::getTripsMap(){
    return tripsInfo;
}
