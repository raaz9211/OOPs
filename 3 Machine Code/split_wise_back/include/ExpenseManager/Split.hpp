#pragma once

#include <memory>
#include <string>

#include "Utils/Enums.hpp"


class Split {
protected:
    std::string userId;
    double amount; // Share amount for this split

public:
    Split(const std::string &userId, double amount = 0.0);

    virtual ~Split() = default;

    virtual bool validate(double totalAmount, int numUsers) const = 0;


    // Getters
    const std::string& getUserId() const;
    double getAmount() const;

    // Setter
    void setAmount(double newAmount);
};