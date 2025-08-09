#pragma once

#include "PaymentMode.hpp"
#include <string>
#include <iostream>

class Card : public PaymentMode {
    std::string cardNumber;
    std::string cardHolder;

public:
    Card(const std::string &number, const std::string & name)
    : cardNumber(number), cardHolder(name) {}

    bool initiate(double amount) override {
        std::cout << "Cade Payment initiate. \n";
        return true;
    }

    std::string getType() const override { return "Card"; }
    const std::string& getCardNumber() const { return cardNumber; }
    const std::string& getCardHolder() const { return cardHolder; }

};