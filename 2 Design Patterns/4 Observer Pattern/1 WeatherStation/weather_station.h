#ifndef WEATHER_STATION_H
#define WEATHER_STATION_H

#include <algorithm>
#include <vector>
#include "observer.h"

class WeatherStation {
private:
    std::vector<Observer*> observers;
    float temperature;

public:
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notifyObservers();
    void setTemperature(float newTemperature);
};
#endif // WEATHER_STATION_H