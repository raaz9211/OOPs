#include <algorithm>
#include <vector>
#include "weather_station.h"


void WeatherStation::addObserver(Observer* observer){
    WeatherStation::observers.push_back(observer);
}

void WeatherStation::removeObserver(Observer* observer){
    WeatherStation::observers.erase(
        std::remove(WeatherStation::observers.begin(), WeatherStation::observers.end(), observer),
        WeatherStation::observers.end());
}

void WeatherStation::notifyObservers() {
    for(Observer *observer : WeatherStation::observers){
        observer->update(temperature);
    }
}

void WeatherStation::setTemperature(float newTemperature) {
    temperature = newTemperature;
    notifyObservers(); // Notify all observers of the change
}
