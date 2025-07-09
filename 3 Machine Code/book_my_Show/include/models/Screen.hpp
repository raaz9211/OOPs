#pragma once

#include <vector>
#include <memory>
#include <string>

#include "models/Seat.hpp"

class Screen {
private:
    int id;
    std::string name;
    std::vector<std::shared_ptr<Seat>> seats;

public:
    Screen(int id, const std::string &name)
    : id(id), name(name) {}

    int getId() const {
        return id;
    }

    const std::string &getName() const {
        return name;
    }

    const std::vector<std::shared_ptr<Seat>> &getSeats() const {
        return seats;
    }

    void addSeat(const std::shared_ptr<Seat> &seat) {
        seats.push_back(seat);
    }
};