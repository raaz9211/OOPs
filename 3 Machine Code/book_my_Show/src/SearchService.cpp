
#include "services/SearchService.hpp"

SearchService::SearchService (
    const std::vector<std::shared_ptr<City>> &cities,
    const std::vector<std::shared_ptr<Theatre>> &theatres,
    const std::vector<std::shared_ptr<Show>> &shows
) : cities(cities), theatres(theatres), shows(shows) {}



std::vector<std::shared_ptr<Show>> SearchService::searchShowsByCity(const std::string &cityName) const {
    std::vector<std::shared_ptr<Show>> result;

    for (const auto &show : shows) {
        auto theatre = show->getTheatre();
        if(theatre && theatre->getCity()->getName() == cityName) {
            result.push_back(show);
        }
    }
    return result;
}


std::vector<std::shared_ptr<Show>> SearchService::searchShowsByEventType(EventType type) const {
    std::vector<std::shared_ptr<Show>> result;

    for (const auto &show : shows) {
        if(show->getEvent()->getEventType() == type) {
            result.push_back(show);
        }
    }
    return result;
}

std::vector<std::shared_ptr<Show>> SearchService::searchShowsByCityAndEvent(const std::string &cityName,  EventType type) const{
    std::vector<std::shared_ptr<Show>> result;

    for (const auto &show : shows) {
        auto theatre = show->getTheatre();
        if(theatre && theatre->getCity()->getName() == cityName
            && show->getEvent()->getEventType() == type) {
            result.push_back(show);
        }
    }
    return result;
};