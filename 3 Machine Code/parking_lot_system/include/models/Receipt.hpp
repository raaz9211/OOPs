#pragma once

#include <string>
#include <memory>
#include <chrono>

#include "Ticket.hpp"

class Receipt
{
private:
    std::string receiptId;
    std::chrono::system_clock::time_point exitTime;
    double fee;
    std::shared_ptr<Ticket> ticket;

public:
    Receipt(const std::string &id, std::shared_ptr<Ticket> ticket, double fee, std::chrono::system_clock::time_point exitTime);

    std::string getReceiptId() const;
    std::chrono::system_clock::time_point getExitTime() const;
    std::shared_ptr<Ticket> getTicket() const;
    double getFee() const;

    std::chrono::duration<double> getDuration() const;
};