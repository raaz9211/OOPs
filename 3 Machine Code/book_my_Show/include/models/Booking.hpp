#pragma once

#include <vector>
#include <memory>

#include "User.hpp"
#include "Show.hpp"
#include "Seat.hpp"
#include "enums/BookingStatus.hpp"

class Booking {
private:
    int id;
    std::shared_ptr<Show> show;
    std::shared_ptr<User> user;
    std::vector<std::shared_ptr<Seat>> bookedSeats;
    BookingStatus status;
public:
    Booking(int id,
    std::shared_ptr<User> user,
    std::shared_ptr<Show> show,
    std::vector<std::shared_ptr<Seat>> bookedSeats,
    BookingStatus status = BookingStatus::PENDING)
    : id(id), user(user), show(show), bookedSeats(bookedSeats), status(status) {}
    
    int getId() const {
        return id;
    }

    const std::shared_ptr<User>& getUser() const {
        return user;
    }

    const std::shared_ptr<Show>& getShow() const {
        return show;
    }

    const std::vector<std::shared_ptr<Seat>>& getSeats() const {
        return bookedSeats;
    }

    BookingStatus getStatus() const {
        return status;
    }

    void confirm() {
        status = BookingStatus::CONFIRMED;
    }

    void cancel() {
        status = BookingStatus::CANCELLED;
    }
};