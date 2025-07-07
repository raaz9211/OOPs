#include <memory>
#include <iostream>
#include <thread>
#include <chrono>

#include "models/ParkingSlot.hpp"
#include "models/ParkingFloor.hpp"
#include "models/ParkingLot.hpp"
#include "models/Vehicle.hpp"
#include "models/Receipt.hpp"
#include "models/EntryGate.hpp"
#include "models/ExitGate.hpp"

#include "services/TicketService.hpp"
#include "services/FlatRateFeeStrategy.hpp"
#include "services/HourlyFeeStrategy.hpp"
#include "services/NearestSlotStrategy.hpp"
#include "services/ParkingLotManager.hpp"

#include "utils/DisplayBoard.hpp"


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

    // // 4th.1 phase
    // auto ticket = std::make_shared<Ticket>("T123", std::make_shared<Vehicle>("DL01CA1234", VehicleType::CAR), std::make_shared<ParkingSlot>(101, SlotType::CAR_SLOT), 1);
    // auto exitGate = std::make_shared<ExitGate>(2, "Exit-1", std::make_shared<FlatRateFeeStrategy>(50.0));
    // auto receipt = exitGate->processVehicleExit(ticket);

    // // 4th.2 phase
    // auto ticket = std::make_shared<Ticket>("T123", std::make_shared<Vehicle>("DL01CA1234", VehicleType::CAR), std::make_shared<ParkingSlot>(101, SlotType::CAR_SLOT), 1);
    // auto feeStrategy = std::make_shared<HourlyFeeStrategy>(20.0);  // ₹20/hour
    // auto exitGate = std::make_shared<ExitGate>(2, "Exit-1", feeStrategy);
    // auto receipt = exitGate->processVehicleExit(ticket);



    
    // // // 5th phase

    // // Step 1: Create the parking lot
    // ParkingLot lot;

    // // Step 2: Create and add floors
    // auto floor0 = std::make_shared<ParkingFloor>(0);
    // floor0->addSlot(std::make_shared<ParkingSlot>(101, SlotType::CAR_SLOT));
    // floor0->addSlot(std::make_shared<ParkingSlot>(102, SlotType::BIKE_SLOT));

    // auto floor1 = std::make_shared<ParkingFloor>(1);
    // floor1->addSlot(std::make_shared<ParkingSlot>(201, SlotType::CAR_SLOT));
    // floor1->addSlot(std::make_shared<ParkingSlot>(202, SlotType::ELECTRIC_SLOT));

    // lot.addFloor(floor0);
    // lot.addFloor(floor1);

    // // Step 3: Create a vehicle
    // auto car = std::make_shared<Vehicle>("KA-01-HH-9999", VehicleType::CAR);

    // // Step 4: Apply Nearest Slot Strategy
    // NearestSlotStrategy strategy;
    // auto slot = strategy.getAvailableSlot(lot, car);

    // // Step 5: Print result
    // if (slot) {
    //     slot->assignVehicle(car);  // ✅ Automatically marks it occupied
    //     std::cout << "✅ Allocated Slot ID: " << slot->getId() << std::endl;
    // } else {
    //     std::cout << "❌ No available slot for vehicle type.\n";
    // }


    // 6th Phase 

    // Step 1: Create ParkingLot and add one floor
    auto parkingLot = std::make_shared<ParkingLot>();

    auto floor1 = std::make_shared<ParkingFloor>(1);
    floor1->addSlot(std::make_shared<ParkingSlot>(101, SlotType::CAR_SLOT, floor1->getFloorNumber()));
    floor1->addSlot(std::make_shared<ParkingSlot>(102, SlotType::TRUCK_SLOT, floor1->getFloorNumber()));
    parkingLot->addFloor(floor1);

    // Step 2: Strategies
    auto slotStrategy = std::make_shared<NearestSlotStrategy>();
    auto feeStrategy = std::make_shared<FlatRateFeeStrategy>(50);  // Flat ₹50

    // Step 3: Configure ParkingLotManager
    auto manager = ParkingLotManager::getInstance();
    manager->configure(parkingLot, slotStrategy, feeStrategy);

    // Step 4: Create Gates
    auto entryGate = std::make_shared<EntryGate>(1, "Main Entry", manager->getTicketService());
    auto exitGate = std::make_shared<ExitGate>(2, "Main Exit", feeStrategy);
    manager->registerEntryGate(entryGate);
    manager->registerExitGate(exitGate);

    // 📋 Display availability before entry
    auto board  = floor1->getDisplayBoard();
    std::cout << "\n[DISPLAY] Before Entry:\n";
    board->show();

    // Step 5: Create Vehicle
    auto vehicle = std::make_shared<Vehicle>("KA01AB1234", VehicleType::CAR);

    // Step 6: Vehicle Entry
    auto ticket = manager->handleEntry(vehicle, 1);
    if (ticket) {
        std::cout << "\n[INFO] Ticket Generated: " << ticket->getTicketId() << "\n";
    } else {
        std::cerr << "\n[ERROR] Ticket generation failed.\n";
        return 1;
    }

    // 📋 Display availability after entry
    std::cout << "\n[DISPLAY] After Entry:\n";
    board->show();

    // Simulate time passing
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Step 7: Vehicle Exit
    auto receipt = manager->handleExit(ticket->getTicketId(), 2);
    if (receipt) {
        std::cout << "[INFO] Receipt Generated: " << receipt->getReceiptId() << "\n";
        std::cout << "[INFO] Total Fee: ₹" << receipt->getFee() << "\n";
    } else {
        std::cerr << "[ERROR] Exit failed.\n";
    }

    // 📋 Display availability after exit
    std::cout << "\n[DISPLAY] After Exit:\n";
    board->show();

    return 0;
}