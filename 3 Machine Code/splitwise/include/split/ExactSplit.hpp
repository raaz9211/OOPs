#pragma once

#include "Split.hpp"

class ExactSplit : public Split {
public:
    ExactSplit(const std::shared_ptr<User> &user, double amount)
    : Split(user, amount) {}
};