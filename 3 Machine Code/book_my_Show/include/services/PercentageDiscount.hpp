#pragma once

#include "DiscountStrategy.hpp"
#include <algorithm>

class PercentageDiscount : public DiscountStrategy {
public:
    double applyDiscount(double amount) const override {
        return amount * 0.9; // 10% off
    }
};