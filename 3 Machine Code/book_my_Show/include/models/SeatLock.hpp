#pragma once

#include <memory>
#include <chrono>

#include "Seat.hpp"
#include "User.hpp"

class SeatLock {
private:
    std::shared_ptr<Seat> seat;
    std::shared_ptr<User> user;
    std::chrono::system_clock::time_point lockTime;
    int timeoutInSeconds;

public:
    SeatLock(const std::shared_ptr<Seat>& seat,
             const std::shared_ptr<User>& user,
             int timeoutInSeconds)
             : seat(seat), user(user),
               lockTime(std::chrono::system_clock::now()),
               timeoutInSeconds(timeoutInSeconds) {}
    
    const std::shared_ptr<Seat>& getSeat() const {
        return seat;
    }

    const std::shared_ptr<User>& getUser() const {
        return user;
    }

    bool isLockExpired() const {
        auto now = std::chrono::system_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - lockTime).count();
        return elapsed > timeoutInSeconds;

    }
};