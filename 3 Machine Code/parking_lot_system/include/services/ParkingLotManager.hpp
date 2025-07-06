#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "models/ParkingFloor.hpp"
#include "models/Vehicle.hpp"
#include "models/Ticket.hpp"
#include "models/Receipt.hpp"
#include "models/EntryGate.hpp"
#include "models/ExitGate.hpp"
#include "services/TicketService.hpp"
#include "services/FeeCalculationStrategy.hpp"
#include "services/SlotAllocationStrategy.hpp"

class ParkingLotManager
{
private:
    ParkingLotManager();

    ParkingLotManager(const ParkingLotManager &) = delete;
    ParkingLotManager &operator=(const ParkingLotManager &) = delete;

    static std::shared_ptr<ParkingLotManager> instance;

    std::shared_ptr<ParkingLot> parkingLot;
    std::shared_ptr<TicketService> ticketService;
    std::shared_ptr<FeeCalculationStrategy> feeStrategy;
    std::shared_ptr<SlotAllocationStrategy> slotStrategy;

    std::unordered_map<int, std::shared_ptr<EntryGate>> entryGates;
    std::unordered_map<int, std::shared_ptr<ExitGate>> exitGates;
public:
    static std::shared_ptr<ParkingLotManager> getInstance();

    void configure(
        std::shared_ptr<ParkingLot> lot,
        std::shared_ptr<SlotAllocationStrategy> slotStrat,
        std::shared_ptr<FeeCalculationStrategy> feeStrat);

    void registerEntryGate(std::shared_ptr<EntryGate> gate);
    void registerExitGate(std::shared_ptr<ExitGate> gate);
 
    std::shared_ptr<Ticket> handleEntry(const std::shared_ptr<Vehicle> &vehicle, int entryGateId);
    std::shared_ptr<Receipt> handleExit(const std::string &ticketId, int exitGateId);

    std::shared_ptr<TicketService> getTicketService() const;
};