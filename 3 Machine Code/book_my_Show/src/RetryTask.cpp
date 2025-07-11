#include "models/RetryTask.hpp"
#include <iostream>

RetryTask::RetryTask(std::shared_ptr<User> user,
              std::shared_ptr<Show> show,
              std::vector<std::shared_ptr<Seat>> seats,
              std::shared_ptr<BookingService> bookingService,
              std::shared_ptr<PaymentService> paymentService)
        : user(user), show(show), seats(seats), 
        bookingService(bookingService),
        paymentService(paymentService),
        attemptCount(0), 
        lastTried(std::chrono::system_clock::now()) {}

bool RetryTask::tryBooking() {
    try {
        attemptCount++;

        lastTried = std::chrono::system_clock::now();

        auto booking = bookingService->createBooking(user, show, seats);
        double amount = seats.size() * 200.0;

        if (paymentService->processPayment(user->getId(), amount)) {
            std::cout << "[RETRY SUCCESS] Booking ID: " << booking->getId() << "\n";
            booking->confirm();
            return true;
        }

        std::cout << "[RETRY FAILED] Payment failed\n";
        return false;
    } catch (const std::exception& e) {
        std::cerr << "[RETRY ERROR] " << e.what() << "\n";
        return false;
    }
}

int RetryTask::getAttemptCount() const {
    return attemptCount;
}

std::chrono::system_clock::time_point RetryTask::getLastTriedTime() const {
    return lastTried;
}