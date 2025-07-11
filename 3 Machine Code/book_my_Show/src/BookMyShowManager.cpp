#include "services/BookMyShowManager.hpp"


BookMyShowManager::BookMyShowManager() {
    // Init services with placeholders; real data will be filled in `initialize()`
    auto seatLockManager = std::make_shared<SeatLockManager>(30);
    this->bookingService = std::make_shared<BookingService>(seatLockManager);
    this->paymentService = std::make_shared<PaymentService>();
}

std::shared_ptr<BookMyShowManager> BookMyShowManager::getInstance() {
    static std::shared_ptr<BookMyShowManager> instance(new BookMyShowManager());
    return instance;
}

void BookMyShowManager::initialize() {
    auto city = std::make_shared<City>(1, "Deoghar");
    cities.push_back(city);

    auto screen = std::make_shared<Screen>(1, "Audi 1");
    screen->addSeat(std::make_shared<Seat>(101, "A1", SeatType::REGULAR));
    screen->addSeat(std::make_shared<Seat>(102, "A2", SeatType::REGULAR));
    screen->addSeat(std::make_shared<Seat>(103, "A3", SeatType::REGULAR));

    auto theatre = std::make_shared<Theatre>(1, "PVR Icon", city);
    theatre->addScreen(screen);

    auto movie = std::make_shared<Movie>(
        1, "Inception", "Mind-bending sci-fi thriller", 148, "English",
        EventType::MOVIE,
        std::vector<std::string>{"Leonardo DiCaprio", "Joseph Gordon-Levitt"},
        "Sci-Fi"
    );


    auto showStartTime = std::chrono::system_clock::now();
    auto show = std::make_shared<Show>(1, movie, theatre, screen, showStartTime);
    shows.push_back(show);

    this->searchService = std::make_shared<SearchService>(cities, theatres, shows);

}


// from DB
void BookMyShowManager::initializeFromDatabase(const std::shared_ptr<DatabaseSimulator>& db) {
    this->cities = db->getCities();
    this->theatres = db->getTheatres();
    this->shows = db->getShows();
    // Rebuild search service with actual data
    this->searchService = std::make_shared<SearchService>(cities, theatres, shows);
}

std::shared_ptr<User> BookMyShowManager::createUser(const std::string &name) {
    int id = users.size() + 1;
    auto user = std::make_shared<User>(id, name);
    users.push_back(user);
    return user;
}

std::vector<std::shared_ptr<Show>> BookMyShowManager::searchShowsByCity(const std::string& cityName){
    return searchService->searchShowsByCity(cityName);
}

std::vector<std::shared_ptr<Show>> BookMyShowManager::searchShowsByEventType(EventType type){
    return searchService->searchShowsByEventType(type);
}

std::shared_ptr<Booking> BookMyShowManager::bookTickets(int userId, int showId, const std::vector<int> &seatIds) {
    auto user = std::find_if(users.begin(), users.end(),
    [userId](const std::shared_ptr<User> &u){ return u->getId() == userId; });

    auto show = std::find_if(shows.begin(), shows.end(),
    [showId](const std::shared_ptr<Show>& s) { return s->getId() == showId; });

    if (user == users.end() || show == shows.end()) {
        throw std::runtime_error("Invalid user or show");
    }

    // Convert seatIds to actual seat objects
    std::vector<std::shared_ptr<Seat>> selectedSeats;
    for(const auto &seat : (*show)->getScreen()->getSeats()) {
        if (std::find(seatIds.begin(), seatIds.end(), seat->getId()) != seatIds.end()) {
            selectedSeats.push_back(seat);
        }
    }

    return bookingService->createBooking(*user, *show, selectedSeats);
}

const std::vector<std::shared_ptr<City>>& BookMyShowManager::getCities() const {
    return cities;
}

const std::vector<std::shared_ptr<Show>>& BookMyShowManager::getShows() const {
    return shows;
}
