#pragma once

#include <memory>
#include <vector>
#include <chrono>

#include "User.hpp"
#include "Show.hpp"
#include "Seat.hpp"

#include "services/BookingService.hpp"
#include "services/PaymentService.hpp"

class RetryTask {
    std::shared_ptr<User> user;
    std::shared_ptr<Show> show;
    std::vector<std::shared_ptr<Seat>> seats;
    std::shared_ptr<BookingService> bookingService;
    std::shared_ptr<PaymentService> paymentService;

    int attemptCount;
    std::chrono::system_clock::time_point lastTried;
public:
    RetryTask(std::shared_ptr<User> user,
              std::shared_ptr<Show> show,
              std::vector<std::shared_ptr<Seat>> seats,
              std::shared_ptr<BookingService> bookingService,
              std::shared_ptr<PaymentService> paymentService);

    bool tryBooking();
    int getAttemptCount() const;
    std::chrono::system_clock::time_point getLastTriedTime() const;
};

