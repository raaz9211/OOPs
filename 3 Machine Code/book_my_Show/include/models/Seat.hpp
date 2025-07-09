#pragma once

#include <string>
#include "../enums/SeatType.hpp"

class Seat {
private:
    int id;
    std::string seatNumber;
    SeatType seatType;
public:
    Seat(int id, const std::string &seatNumber, SeatType seatType)
    : id(id), seatNumber(seatNumber), seatType(seatType) {}

    int getId() const {
        return id;
    }

    const std::string &getSeatNumber() const {
        return seatNumber;
    }

    SeatType getSeatType() const {
        return seatType;
    }
};