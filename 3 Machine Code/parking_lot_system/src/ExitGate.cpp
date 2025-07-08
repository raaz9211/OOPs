#include <string>
#include <iostream>

#include "models/ExitGate.hpp"
#include "services/PaymentService.hpp"


ExitGate::ExitGate(int id, const std::string &name, std::shared_ptr<FeeCalculationStrategy> strategy) :
    Gate(id, name), feeStrategy(strategy) {}

std::shared_ptr<Receipt> ExitGate::processVehicleExit(std::shared_ptr<Ticket> ticket){
    auto now = std::chrono::system_clock::now();
    double fee = feeStrategy->calculateFee(ticket->getEntryTime(), now);
    std::string receiptId = "R-" + ticket->getTicketId();
    
    std::cout << "[INFO] Fee : " << fee << std::endl;
    std::cout << "[INFO] Receipt Id : " << receiptId << std::endl << std::endl;

    bool success = PaymentService::processPayment(fee, PaymentMode::UPI);
    if (!success) {
        std::cerr << "[ERROR] Payment failed. Cannot exit.\n" << std::endl;
        return nullptr;
    }
    return std::make_shared<Receipt>(receiptId, ticket, fee, now); 

}