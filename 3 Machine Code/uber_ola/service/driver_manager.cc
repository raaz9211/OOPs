#include "driver_manager.hpp"


DriverManager &DriverManager::getDriverManager(){
    static DriverManager driverManager;
    return driverManager;
}

void DriverManager::addDriver(string driverName, Driver *driver){
    DriverManager::driversMap[driverName] = driver;
}

Driver *DriverManager::getDriver(string driverName){
    return driversMap[driverName];
}

unordered_map<string, Driver*> DriverManager::getDriverMap(){
    return DriverManager::driversMap;
}
