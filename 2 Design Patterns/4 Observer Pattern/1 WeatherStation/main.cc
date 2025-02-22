#include "weather_station.h"
#include "phone_display.h"
#include "TV_display.h"

int main(){
    WeatherStation weatherStation;

    PhoneDisplay phone_display;
    TVDisplay TV_display;

    // Add observers
    weatherStation.addObserver(&phone_display);
    weatherStation.addObserver(&TV_display);

    // Update weather data
    weatherStation.setTemperature(100);
    weatherStation.setTemperature(400);

    weatherStation.removeObserver(&TV_display);

    weatherStation.setTemperature(200);

}