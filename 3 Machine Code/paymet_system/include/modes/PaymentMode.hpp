#pragma once

#include <string>

class PaymentMode {
public:
    virtual bool initiate(double amount) = 0;
    virtual std::string getType() const = 0;
    virtual ~PaymentMode() = default;
};