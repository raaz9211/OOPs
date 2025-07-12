#pragma once

#include "DiscountStrategy.hpp"
#include <algorithm>

class FlatDiscount : public DiscountStrategy {
public:
    double applyDiscount(double amount) const override {
        return std::max(amount - 50, 0.0);
    }
};