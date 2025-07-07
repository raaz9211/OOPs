#include "utils/DisplayBoard.hpp"

DisplayBoard::DisplayBoard(int floorNumber) : floorNumber(floorNumber) {}

void DisplayBoard::updateSlotAvailability(SlotType type, int count)
{
    availableSlots[type] = count;
}

void DisplayBoard::show() const
{
    std::cout << "🪧 Display Board - Floor " << floorNumber << ":\n";
    for (const auto &entry : availableSlots)
    {
        std::string typeStr;
        switch (entry.first)
        {
        case SlotType::BIKE_SLOT:
            typeStr = "BIKE_SLOT";
            break;
        case SlotType::CAR_SLOT:
            typeStr = "CAR_SLOT";
            break;
        case SlotType::TRUCK_SLOT:
            typeStr = "TRUCK_SLOT";
            break;
        case SlotType::ELECTRIC_SLOT:
            typeStr = "ELECTRIC_SLOT";
            break;
        }
        std::cout << "  " << typeStr << " → " << entry.second << " slots available\n";
    }
}