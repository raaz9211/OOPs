#include <unordered_set>

#include "services/ShowService.hpp"



ShowService::ShowService(std::shared_ptr<SeatLockManager> seatLockManager,
                std::shared_ptr<BookingService> bookingService)
                : seatLockManager(seatLockManager), bookingService(bookingService) {}

std::vector<std::shared_ptr<Seat>> ShowService::getAvailableSeatsForShow(std::shared_ptr<Show> show) const {
    auto allSeats = show->getScreen()->getSeats();
    auto bookedSeats = bookingService->getBookedSeatsForShow(show);

    std::unordered_set<int> bookedSeatIds;
    for(const auto &seat : bookedSeats) {
        bookedSeatIds.insert(seat->getId());
    }

    std::vector<std::shared_ptr<Seat>> availableSeats;

    for (const auto &seat : allSeats) {
        if (!seatLockManager->isSeatLocked(seat) && bookedSeatIds.find(seat->getId()) == bookedSeatIds.end()) {
            availableSeats.push_back(seat);
        }
    }

    return availableSeats;
}