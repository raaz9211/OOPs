#pragma once

#include "services/SeatLockManager.hpp"

SeatLockManager::SeatLockManager(int timeoutInSeconds) : timeoutInSeconds(timeoutInSeconds) {}

void SeatLockManager::lockSeat(const std::shared_ptr<Seat> &seat, const std::shared_ptr<User> &user) {
    std::lock_guard<std::mutex> lock(mtx);

    int seatId = seat->getId();

    auto checkLockedSeat = seatLocks.find(seatId);

    if (checkLockedSeat == seatLocks.end() || checkLockedSeat->second->isLockExpired()) {
        seatLocks[seatId] = std::make_shared<SeatLock>(seat, user, timeoutInSeconds);
        std::cout << "[INFO] seat id " << seatId << " is locked" << std::endl;
        return;
    }

    throw std::runtime_error("Seat is already locked");
}

void SeatLockManager::unlockSeat(const std::shared_ptr<Seat> &seat, const std::shared_ptr<User> &user){
    std::lock_guard<std::mutex> lock(mtx);
    int seatId = seat->getId();

    auto checkLockedSeat = seatLocks.find(seatId);
    if(checkLockedSeat != seatLocks.end() 
    && checkLockedSeat->second->getUser()->getId() == user->getId()){
        seatLocks.erase(checkLockedSeat);
    }
}

bool SeatLockManager::isSeatLocked(const std::shared_ptr<Seat> &seat) {
    std::lock_guard<std::mutex> lock(mtx);

    int seatId = seat->getId();

    auto checkLockedSeat = seatLocks.find(seatId);
    return (checkLockedSeat != seatLocks.end() && !checkLockedSeat->second->isLockExpired());
} 


bool SeatLockManager::isSeatLockedByUser(const std::shared_ptr<Seat>& seat, const std::shared_ptr<User>& user) {
    std::lock_guard<std::mutex> lock(mtx);
    int seatId = seat->getId();

    auto checkLockedSeat = seatLocks.find(seatId);
    return (checkLockedSeat != seatLocks.end() 
            && !checkLockedSeat->second->isLockExpired() 
            && checkLockedSeat->second->getUser()->getId() == user->getId());

}

