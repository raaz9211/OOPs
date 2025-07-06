#include "models/Receipt.hpp"

Receipt::Receipt(const std::string &id, std::shared_ptr<Ticket> ticket, double fee, std::chrono::system_clock::time_point exitTime) 
: receiptId(id), ticket(ticket), fee(fee), exitTime(exitTime) {}


std::string Receipt::getReceiptId() const {
    return receiptId;
}

std::chrono::system_clock::time_point Receipt::getExitTime() const {
    return exitTime;
}

std::shared_ptr<Ticket> Receipt::getTicket() const {
    return ticket;
}

double Receipt::getFee() const {
    return fee;
}


std::chrono::duration<double> Receipt::getDuration() const {
    return exitTime - ticket->getEntryTime();
}