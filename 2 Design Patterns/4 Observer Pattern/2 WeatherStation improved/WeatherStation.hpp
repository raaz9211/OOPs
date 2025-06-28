#pragma once

#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>

#include "IObserver.hpp"

class WeatherStation {
private:
    float temperature;
    std::vector<std::shared_ptr<IObserver>> observers;
public:
    void addObserver(const std::shared_ptr<IObserver> &observer);
    void removeObserver(const std::shared_ptr<IObserver>& observer);
    void setTemperature(float newTemperature);
    void notifyObservers() const;
};