#pragma once

#include <random>
#include <chrono>

class PaymentService {
public:
    // Simulate a payment attempt and return true (success) or false (failure)
    bool processPayment(int userId, double amount);
};