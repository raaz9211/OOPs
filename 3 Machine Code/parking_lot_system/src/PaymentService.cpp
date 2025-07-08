#include "services/PaymentService.hpp"

bool PaymentService::processPayment(double amount, PaymentMode mode)
{
    std::cout << "[PAYMENT] Processing ₹" << amount
              << " via " << getPaymentModeName(mode) << "...\n";

    std::cout << "[PAYMENT] Payment successful!\n";
    return true;
}

std::string PaymentService::getPaymentModeName(PaymentMode mode) {
    switch (mode) {
        case PaymentMode::CASH: return "Cash";
        case PaymentMode::CARD: return "Card";
        case PaymentMode::UPI: return "UPI";
        default: return "Unknown";
    }
}