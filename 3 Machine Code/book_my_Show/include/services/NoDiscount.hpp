#pragma once

#include "DiscountStrategy.hpp"

class NoDiscount : public DiscountStrategy {
public:
    double applyDiscount(double amount) const override {
        return amount;
    }
};