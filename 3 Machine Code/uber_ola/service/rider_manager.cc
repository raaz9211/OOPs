#include "rider_manager.hpp"

RiderManager &RiderManager::getRiderManager(){
    static RiderManager riderManager;
    return riderManager;
}

void RiderManager::addRider(string riderName, Rider* rider){
    RiderManager::ridersMap[riderName] = rider;
}

Rider *RiderManager::getRider(string riderName){
    return RiderManager::ridersMap[riderName];
}

