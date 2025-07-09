#pragma once

#include <vector>
#include <memory>

#include "models/Show.hpp"
#include "models/Seat.hpp"
#include "services/SeatLockManager.hpp"
#include "services/BookingService.hpp"


class ShowService {
private:
    std::shared_ptr<SeatLockManager> seatLockManager;
    std::shared_ptr<BookingService> bookingService;

public:
    ShowService(std::shared_ptr<SeatLockManager> seatLockManager,
                std::shared_ptr<BookingService> bookingService);

    std::vector<std::shared_ptr<Seat>> getAvailableSeatsForShow(std::shared_ptr<Show> show) const;
};