#include "WeatherStation.hpp"

void WeatherStation::addObserver(const std::shared_ptr<IObserver> &observer)
{
    observers.push_back(observer);
    std::cout << "[WeatherStation] Observer added.\n";
}

void WeatherStation::removeObserver(const std::shared_ptr<IObserver> &observer)
{
    observers.erase(
        std::remove_if(observers.begin(), observers.end(),
                       [&observer](const std::shared_ptr<IObserver> &obs)
                       {
                           return obs == observer;
                       }),
        observers.end());
    std::cout << "[WeatherStation] Observer removed.\n";
}

void WeatherStation::setTemperature(float newTemperature)
{
    if (temperature != newTemperature)
    {
        temperature = newTemperature;
        std::cout << "[WeatherStation] Temperature updated to: " << temperature << "\n";
        notifyObservers();
    }
}

void WeatherStation::notifyObservers() const
{
    for (const auto &observer : observers)
    {
        observer->update(temperature);
    }
}