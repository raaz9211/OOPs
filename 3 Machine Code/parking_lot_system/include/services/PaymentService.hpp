#pragma once

#include <string>
#include <memory>
#include <iostream>

#include "../enums/PaymentMode.hpp"

class PaymentService {
public:
    static bool processPayment(double amount, PaymentMode mode);
    static std::string getPaymentModeName(PaymentMode mode);

};