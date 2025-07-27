#pragma once

#include "Split.hpp"

class PercentSplit : public Split {
private:
    double percent;
public:
    PercentSplit(const std::shared_ptr<User> &user, double amount, double percent)
    : Split(user, amount), percent(percent) {}

    double getPercent() const override {return percent;}
};