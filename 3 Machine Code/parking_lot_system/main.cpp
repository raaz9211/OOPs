#include <iostream>

#include "models/ParkingSlot.hpp"
#include "models/ParkingFloor.hpp"
#include "models/ParkingLot.hpp"
#include "models/Vehicle.hpp"
#include "models/Receipt.hpp"
#include "services/TicketService.hpp"
#include "services/FlatRateFeeStrategy.hpp"
#include "models/ExitGate.hpp"

int main() {
    // // First phase
    // auto vechicle = std::make_shared<Vehicle>("DL01AB1234", VehicleType::CAR);
    // ParkingSlot slot(101, SlotType::CAR_SLOT);
    // slot.assignVehicle(vechicle);

    // std::cout << "Slot ID: " << slot.getId()
    //           << " | Occupied: " << slot.isOccupied()
    //           << " | Vehicle: " << slot.getParkedVehicle()->getNumberPlate()
    //           << std::endl;

    // slot.removeVehicle();
    // std::cout << "After removal - Occupied: " << slot.isOccupied() << std::endl;

    // // Second phase
    // auto floor = std::make_shared<ParkingFloor>(1);
    // floor->addSlot(std::make_shared<ParkingSlot>(101, SlotType::CAR_SLOT));
    // floor->addSlot(std::make_shared<ParkingSlot>(102, SlotType::BIKE_SLOT));

    // auto availableCarSlot = floor->getNextAvailableSlot(SlotType::CAR_SLOT);
    // if (availableCarSlot) {
    //     std::cout << "Available car slot: " << availableCarSlot->getId() << std::endl;
    // }


    // availableCarSlot = floor->getNextAvailableSlot(SlotType::BIKE_SLOT);
    // if (availableCarSlot) {
    //     std::cout << "Available car slot: " << availableCarSlot->getId() << std::endl;
    // }

    // //3rd Phase
    // auto lot = std::make_shared<ParkingLot>();
    // auto floor1 = std::make_shared<ParkingFloor>(1);
    // floor1->addSlot(std::make_shared<ParkingSlot>(101, SlotType::CAR_SLOT));
    // floor1->addSlot(std::make_shared<ParkingSlot>(102, SlotType::CAR_SLOT));
    // floor1->addSlot(std::make_shared<ParkingSlot>(103, SlotType::BIKE_SLOT));
    // lot->addFloor(floor1);

    // auto floor2 = std::make_shared<ParkingFloor>(2);
    // floor1->addSlot(std::make_shared<ParkingSlot>(201, SlotType::CAR_SLOT));
    // lot->addFloor(floor2);


    // auto slot = lot->getNextAvailableSlot(SlotType::CAR_SLOT);

    // if (slot) {
    //     std::cout << "Slot found: " << slot->getId() << std::endl;
    // }

    // std::cout << std::endl;

    // for (auto _slot : lot->getAllAvailableSlots(SlotType::CAR_SLOT)){
    //     std::cout << "Slot found: " << _slot->getId() << std::endl;

    // }

    // std::cout << std::endl;

    // slot = lot->getNextAvailableSlot(SlotType::BIKE_SLOT);

    // if (slot) {
    //     std::cout << "Slot found: " << slot->getId() << std::endl;
    // }

    // // 4th phase
    // auto car = std::make_shared<Vehicle>("DL01CA1234", VehicleType::CAR);
    // std::cout << "Vehicle Number: " << car->getVehicleNumber() << "\n";

    // // 4th phase
    // auto ticket = std::make_shared<Ticket>("T123", std::make_shared<Vehicle>("DL01CA1234", VehicleType::CAR), std::make_shared<ParkingSlot>(101, SlotType::CAR_SLOT), 1);
    // auto receipt = std::make_shared<Receipt>("R123", ticket, 80.0);
    // std::cout << receipt->getReceipId() << std::endl;

    auto ticket = std::make_shared<Ticket>("T123", std::make_shared<Vehicle>("DL01CA1234", VehicleType::CAR), std::make_shared<ParkingSlot>(101, SlotType::CAR_SLOT), 1);
    auto exitGate = std::make_shared<ExitGate>(2, "Exit-1", std::make_shared<FlatRateFeeStrategy>(50.0));
    auto receipt = exitGate->processVehicleExit(ticket);

}