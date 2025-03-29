#pragma once

#include "../entity/rider.hpp"


class RiderManager {
    RiderManager() {}
    unordered_map<string, Rider*> ridersMap;
public:
    static RiderManager &getRiderManager();
    void addRider(string riderName, Rider* rider);
    Rider* getRider(string riderName);
};