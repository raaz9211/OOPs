#pragma once

#include <string>
#include <vector>
#include <memory>

#include "models/City.hpp"
#include "models/Theatre.hpp"
#include "models/Show.hpp"
#include "enums/EventType.hpp"

class SearchService {
private:
    std::vector<std::shared_ptr<City>> cities;
    std::vector<std::shared_ptr<Theatre>> theatres;
    std::vector<std::shared_ptr<Show>> shows;
public:
    SearchService(
        const std::vector<std::shared_ptr<City>>& cities,
        const std::vector<std::shared_ptr<Theatre>>& theatres,
        const std::vector<std::shared_ptr<Show>>& shows
    );

    std::vector<std::shared_ptr<Show>> searchShowsByCity(const std::string &cityName) const;
    std::vector<std::shared_ptr<Show>> searchShowsByEventType(EventType type) const;
    std::vector<std::shared_ptr<Show>> searchShowsByCityAndEvent(const std::string &cityName,  EventType type) const;

};