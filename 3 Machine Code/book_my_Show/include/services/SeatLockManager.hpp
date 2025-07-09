#pragma once

#include <unordered_map>
#include <vector>
#include <memory>
#include <mutex>
#include <stdexcept>
#include <iostream>

#include "models/Seat.hpp"
#include "models/User.hpp"
#include "models/SeatLock.hpp"

class SeatLockManager {
private:
    int timeoutInSeconds;
    std::unordered_map<int, std::shared_ptr<SeatLock>> seatLocks;
    std::mutex mtx;

public:
    SeatLockManager(int timeoutInSeconds);
    
    void lockSeat(const std::shared_ptr<Seat>& seat, const std::shared_ptr<User>& user);
    void unlockSeat(const std::shared_ptr<Seat>& seat, const std::shared_ptr<User>& user);
    bool isSeatLocked(const std::shared_ptr<Seat>& seat);
    bool isSeatLockedByUser(const std::shared_ptr<Seat>& seat, const std::shared_ptr<User>& user);
};

