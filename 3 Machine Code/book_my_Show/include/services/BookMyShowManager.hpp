#pragma once

#include <memory>
#include <vector>
#include <algorithm>

#include "models/City.hpp"
#include "models/Theatre.hpp"
#include "models/Show.hpp"
#include "models/Seat.hpp"
#include "models/User.hpp"
#include "models/Movie.hpp"

#include "services/SearchService.hpp"
#include "services/BookingService.hpp"
#include "services/PaymentService.hpp"
#include "services/SeatLockManager.hpp"
#include "services/RetryQueueManager.hpp"

#include "../admin/DatabaseSimulator.hpp"


class BookMyShowManager {
private:
    std::vector<std::shared_ptr<City>> cities;
    std::vector<std::shared_ptr<Theatre>> theatres;
    std::vector<std::shared_ptr<Show>> shows;
    std::vector<std::shared_ptr<User>> users;

    std::shared_ptr<SearchService> searchService;
    std::shared_ptr<BookingService> bookingService;
    std::shared_ptr<SeatLockManager> seatLockManager;
    std::shared_ptr<PaymentService> paymentService;
    std::shared_ptr<RetryQueueManager> retryQueueManager;


    BookMyShowManager();
    BookMyShowManager(const BookMyShowManager &) = delete;
    BookMyShowManager &operator=(const BookMyShowManager &) = delete;

public:

    static std::shared_ptr<BookMyShowManager> getInstance();
    void initialize();
    void initializeFromDatabase(const std::shared_ptr<DatabaseSimulator>& db);


    std::shared_ptr<User> createUser(const std::string &name);

    std::vector<std::shared_ptr<Show>> searchShowsByCity(const std::string& cityName);
    std::vector<std::shared_ptr<Show>> searchShowsByEventType(EventType type);

    std::shared_ptr<Booking> bookTickets(int userId, int showId, const std::vector<int> &seatIds);

    const std::vector<std::shared_ptr<City>>& getCities() const;
    const std::vector<std::shared_ptr<Show>>& getShows() const;

    std::shared_ptr<RetryQueueManager> getRetryQueueManager() const;

};