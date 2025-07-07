#pragma once

#include "../enums/SlotType.hpp"
#include <unordered_map>
#include <string>
#include <memory>
#include <iostream>

class DisplayBoard {
private:
    int floorNumber;
    std::unordered_map<SlotType, int> availableSlots;
public:
    DisplayBoard(int floorNumber);

    void updateSlotAvailability(SlotType type, int count);
    void show() const;
};