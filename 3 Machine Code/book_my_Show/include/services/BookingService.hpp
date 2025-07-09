#pragma once

#include <memory>
#include <vector>

#include "models/Seat.hpp"
#include "models/User.hpp"
#include "models/Show.hpp"
#include "models/Booking.hpp"
#include "SeatLockManager.hpp"

class BookingService {
private:
    std::vector<std::shared_ptr<Booking>> bookings;
    std::shared_ptr<SeatLockManager> seatLockManager;
    int bookingId = 0;
public:
    BookingService(std::shared_ptr<SeatLockManager> seatLockManager);

    std::shared_ptr<Booking> createBooking (
        std::shared_ptr<User> user,
        std::shared_ptr<Show> show,
        const std::vector<std::shared_ptr<Seat>> &seats
    );

    std::vector<std::shared_ptr<Seat>> getBookedSeatsForShow(std::shared_ptr<Show> show) const;
    std::vector<std::shared_ptr<Booking>> getAllBookings() const;

};