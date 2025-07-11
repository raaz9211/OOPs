#include "../admin/AdminPanel.hpp"

AdminPanel::AdminPanel(const std::shared_ptr<DatabaseSimulator> &database)
    :db(database) {}


std::shared_ptr<City> AdminPanel::addCity(int id, const std::string &name) {
    auto city = std::make_shared<City>(id, name);
    db->addCity(city);
    return city;
}

// Add Theatre
std::shared_ptr<Theatre> AdminPanel::addTheatre(int id, const std::string& name, const std::shared_ptr<City>& city) {
    auto theatre = std::make_shared<Theatre>(id, name, city);
    db->addTheatre(theatre);
    return theatre;
}

// Add Screen
std::shared_ptr<Screen> AdminPanel::addScreen(int id, const std::string& name, const std::shared_ptr<Theatre>& theatre) {
    auto screen = std::make_shared<Screen>(id, name);
    theatre->addScreen(screen);
    db->addScreen(screen);
    return screen;
}

// Add Seat
std::shared_ptr<Seat> AdminPanel::addSeat(int id, const std::string& seatNumber, SeatType type, const std::shared_ptr<Screen>& screen) {
    auto seat = std::make_shared<Seat>(id, seatNumber, type);
    screen->addSeat(seat);
    db->addSeat(seat);
    return seat;
}

// Add Movie
std::shared_ptr<Movie> AdminPanel::addMovie(int id, const std::string& name, const std::string& description,
                                            int duration, const std::string& language,
                                            const std::vector<std::string>& cast, const std::string& genre) {
    auto movie = std::make_shared<Movie>(id, name, description, duration, language, EventType::MOVIE, cast, genre);
    db->addEvent(movie);
    return movie;
}

// Add Concert
std::shared_ptr<Concert> AdminPanel::addConcert(int id, const std::string& name, const std::string& description,
                                                int duration, const std::string& language,
                                                const std::vector<std::string> artists, const bool isVIPAvailable) {
    auto concert = std::make_shared<Concert>(id, name, description, duration, language, EventType::CONCERT, artists, isVIPAvailable);
    db->addEvent(concert);
    return concert;
}

// Add Show
std::shared_ptr<Show> AdminPanel::addShow(int id, const std::shared_ptr<Event>& event,
                                          const std::shared_ptr<Theatre>& theatre,
                                          const std::shared_ptr<Screen>& screen,
                                          const std::chrono::system_clock::time_point& startTime) {
    auto show = std::make_shared<Show>(id, event, theatre, screen, startTime);
    db->addShow(show);
    return show;
}