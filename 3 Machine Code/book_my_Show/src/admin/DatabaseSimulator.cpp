#include "../admin/DatabaseSimulator.hpp"

// City
void DatabaseSimulator::addCity(const std::shared_ptr<City>& city) {
    cities.push_back(city);
}

const std::vector<std::shared_ptr<City>>& DatabaseSimulator::getCities() const {
    return cities;
}

// Theatre
void DatabaseSimulator::addTheatre(const std::shared_ptr<Theatre>& theatre) {
    theatres.push_back(theatre);
}

const std::vector<std::shared_ptr<Theatre>>& DatabaseSimulator::getTheatres() const {
    return theatres;
}

// Screen
void DatabaseSimulator::addScreen(const std::shared_ptr<Screen>& screen) {
    screens.push_back(screen);
}

const std::vector<std::shared_ptr<Screen>>& DatabaseSimulator::getScreens() const {
    return screens;
}

// Seat
void DatabaseSimulator::addSeat(const std::shared_ptr<Seat>& seat) {
    seats.push_back(seat);
}

const std::vector<std::shared_ptr<Seat>>& DatabaseSimulator::getSeats() const {
    return seats;
}

// Show
void DatabaseSimulator::addShow(const std::shared_ptr<Show>& show) {
    shows.push_back(show);
}

const std::vector<std::shared_ptr<Show>>& DatabaseSimulator::getShows() const {
    return shows;
}

// User
void DatabaseSimulator::addUser(const std::shared_ptr<User>& user) {
    users.push_back(user);
}

const std::vector<std::shared_ptr<User>>& DatabaseSimulator::getUsers() const {
    return users;
}

// Event
void DatabaseSimulator::addEvent(const std::shared_ptr<Event>& event) {
    events.push_back(event);
}

const std::vector<std::shared_ptr<Event>>& DatabaseSimulator::getEvents() const {
    return events;
}
