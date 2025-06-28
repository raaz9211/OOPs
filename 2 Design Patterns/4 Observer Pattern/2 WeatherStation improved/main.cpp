#include <memory>
#include <chrono>
#include <thread>

#include "WeatherStation.hpp"
#include "PhoneDisplay.hpp"
#include "TVDisplay.hpp"

int main() {
    auto weatherStation = std::make_shared<WeatherStation>();

    auto phoneDisplay = std::make_shared<PhoneDisplay>();
    auto tvDisplay = std::make_shared<TVDisplay>();

    weatherStation->addObserver(phoneDisplay);
    weatherStation->addObserver(tvDisplay);

    weatherStation->setTemperature(100);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    weatherStation->setTemperature(400);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    weatherStation->removeObserver(tvDisplay);

    weatherStation->setTemperature(200);

    return 0;
}
