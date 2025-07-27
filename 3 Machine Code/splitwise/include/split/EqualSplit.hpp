#pragma once

#include "Split.hpp"

class EqualSplit : public Split {
public:
    EqualSplit(const std::shared_ptr<User> &user, double amount)
    : Split(user, amount) {}
};