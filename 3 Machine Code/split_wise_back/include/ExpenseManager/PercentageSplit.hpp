#pragma once

#include "Split.hpp"


class PercentageSplit : public Split {
private:
    double percentage;
public:
    PercentageSplit(const std::string &userId, double amount, double percentage);

    bool validate(double totalAmount, int numUsers) const override;

    double getPercentage() const;

    void setPercentage(double newPercentage);
};