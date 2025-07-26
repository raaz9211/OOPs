#pragma once

#include "Split.hpp"


class ExactSplit : public Split {

public:
    ExactSplit(const std::string &userId, double amount);

    bool validate(double totalAmount, int numUsers) const override;

};