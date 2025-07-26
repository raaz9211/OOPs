#pragma once

#include "Split.hpp"


class EqualSplit : public Split {

public:
    EqualSplit(const std::string &userId, double amount);

    bool validate(double totalAmount, int numUsers) const override;

};