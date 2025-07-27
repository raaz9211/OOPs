#pragma once

#include <memory>

#include "../user/User.hpp"

class Split {

protected:
    std::shared_ptr<User> user;
    double amount;
public:
    Split(const std::shared_ptr<User> &user, double amount)
    : user(user), amount(amount) {}

    virtual ~Split() = default;

    std::shared_ptr<User> getUser() const { return user; }
    double getAmount() const { return amount; }
    virtual double getPercent() const { return 0.0; } // Only for PercentSplit
    
};