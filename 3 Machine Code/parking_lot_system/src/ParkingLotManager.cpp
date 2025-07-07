#include "services/ParkingLotManager.hpp"
#include <iostream>
#include <chrono>

ParkingLotManager::ParkingLotManager() = default;

std::shared_ptr<ParkingLotManager> ParkingLotManager::getInstance() {
    static std::shared_ptr<ParkingLotManager> instance(new ParkingLotManager());
    return instance;
}


void ParkingLotManager::configure(
        std::shared_ptr<ParkingLot> lot,
        std::shared_ptr<SlotAllocationStrategy> slotStrat,
        std::shared_ptr<FeeCalculationStrategy> feeStrat
) {
    this->parkingLot = lot;
    this->slotStrategy = slotStrat;
    this->feeStrategy = feeStrat;

    this->ticketService = std::make_shared<TicketService>();
}

void ParkingLotManager::registerEntryGate(std::shared_ptr<EntryGate> gate) {
    entryGates[gate->getId()] = gate;
}

void ParkingLotManager::registerExitGate(std::shared_ptr<ExitGate> gate) {
    exitGates[gate->getId()] = gate;
}


std::shared_ptr<Ticket> ParkingLotManager::handleEntry(const std::shared_ptr<Vehicle> &vehicle, int entryGateId) {
    if(!ticketService or !parkingLot or !slotStrategy) {
        std::cerr << "[ERROR] ParkingLotManager is not fully configured.\n";
        return nullptr;
    }

    auto gateIt = entryGates.find(entryGateId);
    if (gateIt == entryGates.end()) {
        std::cerr << "[ERROR] Entry gate not found.\n";
        return nullptr;
    }

    auto slot = slotStrategy->getAvailableSlot(*parkingLot, vehicle);
    if(!slot) {
        std::cerr << "[ERROR] No available slot for this vehicle type.\n";
        return nullptr;
    }

    slot->assignVehicle(vehicle);
    auto floor = parkingLot->getFloor(slot->getFloorNumber());
    if (floor) {
        floor->updateDisplayBoard();
    }

    return gateIt->second->processVehicleEntry(vehicle, slot);
}

std::shared_ptr<Receipt> ParkingLotManager::handleExit(const std::string &ticketId, int exitGateId){
    if(!ticketService or !feeStrategy) {
        std::cerr << "[ERROR] ParkingLotManager not properly configured for exit.\n";
        return nullptr;
    }

    auto gateIt = exitGates.find(exitGateId);
    if (gateIt == exitGates.end()) {
        std::cerr << "[ERROR] Exit gate not found.\n";
        return nullptr;
    }

    auto ticket = ticketService->getTicket(ticketId);
    if (!ticket) {
        std::cerr << "[ERROR] Invalid ticket ID: " << ticketId << "\n";
        return nullptr;
    }

    auto slot = ticket->getParkingSlot();
    if (slot) {
        slot->removeVehicle();
    }
    
    auto floor = parkingLot->getFloor(ticket->getParkingSlot()->getFloorNumber());
    if (floor) {
        floor->updateDisplayBoard();
    }

    return gateIt->second->processVehicleExit(ticket);
}

std::shared_ptr<TicketService> ParkingLotManager::getTicketService() const {
    return ticketService;
}