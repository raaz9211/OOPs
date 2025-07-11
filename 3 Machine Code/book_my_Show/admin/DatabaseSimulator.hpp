#pragma once

#include <vector>
#include <memory>
#include <unordered_map>
#include <string>

#include "models/City.hpp"
#include "models/Theatre.hpp"
#include "models/Screen.hpp"
#include "models/Seat.hpp"
#include "models/Show.hpp"
#include "models/User.hpp"
#include "models/Event.hpp"

class DatabaseSimulator {
private:
    std::vector<std::shared_ptr<City>> cities;
    std::vector<std::shared_ptr<Theatre>> theatres;
    std::vector<std::shared_ptr<Screen>> screens;
    std::vector<std::shared_ptr<Seat>> seats;
    std::vector<std::shared_ptr<Show>> shows;
    std::vector<std::shared_ptr<User>> users;
    std::vector<std::shared_ptr<Event>> events;

public:

    // City
    void addCity(const std::shared_ptr<City>& city);
    const std::vector<std::shared_ptr<City>>& getCities() const;

    // Theatre
    void addTheatre(const std::shared_ptr<Theatre>& theatre);
    const std::vector<std::shared_ptr<Theatre>>& getTheatres() const;

    // Screen
    void addScreen(const std::shared_ptr<Screen>& screen);
    const std::vector<std::shared_ptr<Screen>>& getScreens() const;

    // Seat
    void addSeat(const std::shared_ptr<Seat>& seat);
    const std::vector<std::shared_ptr<Seat>>& getSeats() const;

    // Show
    void addShow(const std::shared_ptr<Show>& show);
    const std::vector<std::shared_ptr<Show>>& getShows() const;

    // User
    void addUser(const std::shared_ptr<User>& user);
    const std::vector<std::shared_ptr<User>>& getUsers() const;

    // Event (Movie / Concert)
    void addEvent(const std::shared_ptr<Event>& event);
    const std::vector<std::shared_ptr<Event>>& getEvents() const;

};