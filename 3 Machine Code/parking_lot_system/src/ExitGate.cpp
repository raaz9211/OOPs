#include "models/ExitGate.hpp"
#include <string>
#include <iostream>

ExitGate::ExitGate(int id, const std::string &name, std::shared_ptr<FeeCalculationStrategy> strategy) :
    Gate(id, name), feeStrategy(strategy) {}

std::shared_ptr<Receipt> ExitGate::processVehicleExit(std::shared_ptr<Ticket> ticket){
    auto now = std::chrono::system_clock::now();
    double fee = feeStrategy->calculateFee(ticket->getEntryTime(), now);

    std::string receiptId = "R-" + ticket->getTicketId();
    
    std::cout << "Fee : " << fee << std::endl;
    std::cout << "Receipt Id : " << receiptId << std::endl;

    return std::make_shared<Receipt>(receiptId, ticket, fee, now); 

}