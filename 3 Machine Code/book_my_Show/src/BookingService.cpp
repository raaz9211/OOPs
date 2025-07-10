#include <stdexcept>
#include <algorithm>

#include "services/BookingService.hpp"


BookingService::BookingService(std::shared_ptr<SeatLockManager> seatLockManager)
    : seatLockManager(seatLockManager), bookingId(bookingId) {}

std::shared_ptr<Booking> BookingService::createBooking(
    std::shared_ptr<User> user,
    std::shared_ptr<Show> show,
    const std::vector<std::shared_ptr<Seat>> &seats
){
    for (const auto &seat : seats){
        if (!seatLockManager->isSeatLocked(seat)) {
            seatLockManager->lockSeat(seat, user);
        } else if(!seatLockManager->isSeatLockedByUser(seat, user)){
            throw std::runtime_error("Seat already locked by another user: " + std::to_string(seat->getId()));
        }

    }

    auto booking = std::make_shared<Booking>(++bookingId, user, show, seats, BookingStatus::CONFIRMED);

    bookings.push_back(booking);

    return booking;
}

std::vector<std::shared_ptr<Seat>> BookingService::getBookedSeatsForShow(std::shared_ptr<Show> show) const {
    std::vector<std::shared_ptr<Seat>> bookedSeats;

    for (const auto &booking : bookings) {
        if (booking->getShow()->getId() == show->getId()) {
            const auto &seats = booking->getSeats();
            bookedSeats.insert(bookedSeats.end(), seats.begin(), seats.end());
        }
    }
    return bookedSeats;
}


std::vector<std::shared_ptr<Booking>> BookingService::getAllBookings() const {
    return bookings;
}