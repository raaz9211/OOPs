#pragma once

#include "PaymentMode.hpp"
#include <string>
#include <iostream>

class UPI : public PaymentMode {

    std::string upiId;

public:
    UPI(const std::string &upiId)
    : upiId(upiId) {}

    bool initiate(double amount) override {
        std::cout << "UPI Payment initiate. \n";
        return true;
    }

    std::string getType() const override { return "UPI"; }
    const std::string& getUpiId() const { return upiId; }
};