#pragma once

#include <memory>
#include <string>
#include <chrono>
#include <vector>

#include "DatabaseSimulator.hpp"
#include "models/City.hpp"
#include "models/Theatre.hpp"
#include "models/Screen.hpp"
#include "models/Seat.hpp"
#include "models/Event.hpp"
#include "models/Movie.hpp"
#include "models/Concert.hpp"
#include "models/Show.hpp"
#include "enums/SeatType.hpp"
#include "enums/EventType.hpp"

class AdminPanel {
private:
    std::shared_ptr<DatabaseSimulator> db;
public:
    AdminPanel(const std::shared_ptr<DatabaseSimulator> &database);

    std::shared_ptr<City> addCity(int id, const std::string& name);
    std::shared_ptr<Theatre> addTheatre(int id, const std::string& name, const std::shared_ptr<City>& city);
    std::shared_ptr<Screen> addScreen(int id, const std::string& name, const std::shared_ptr<Theatre>& theatre);
    std::shared_ptr<Seat> addSeat(int id, const std::string& seatNumber, SeatType type, const std::shared_ptr<Screen>& screen);

    std::shared_ptr<Movie> addMovie(int id, const std::string& name, const std::string& description,
                                    int duration, const std::string& language,
                                    const std::vector<std::string>& cast, const std::string& genre);

    std::shared_ptr<Concert> addConcert(int id, const std::string& name, const std::string& description,
                                        int duration, const std::string& language,
                                        const std::vector<std::string> artists, const bool isVIPAvailable);


    std::shared_ptr<Show> addShow(int id, const std::shared_ptr<Event>& event,
                                  const std::shared_ptr<Theatre>& theatre,
                                  const std::shared_ptr<Screen>& screen,
                                  const std::chrono::system_clock::time_point& startTime);
};