#pragma once

class DiscountStrategy{
public:
    virtual double applyDiscount(double amount) const = 0;
    virtual ~DiscountStrategy() = default;
};