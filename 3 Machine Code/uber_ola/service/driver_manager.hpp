#pragma once
#include "../entity/driver.hpp"

class DriverManager {
    DriverManager() {}
    unordered_map<string, Driver*> driversMap;
public:
    static DriverManager &getDriverManager();
    void addDriver(string driverName, Driver *driver);
    Driver *getDriver(string driverName);
    unordered_map<string, Driver*> getDriverMap();
};