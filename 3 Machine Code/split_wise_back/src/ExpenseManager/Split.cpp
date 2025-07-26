#include "ExpenseManager/Split.hpp"


Split::Split(const std::string &userId, double amount)
    : userId(userId), amount(amount) {}

const std::string& Split::getUserId() const { return userId; }
double Split::getAmount() const { return amount; }
void Split::setAmount(double newAmount) { amount = newAmount; }