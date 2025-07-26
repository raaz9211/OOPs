#include "ExpenseManager/ExactSplit.hpp"
#include "Utils/Constants.hpp"



ExactSplit::ExactSplit(const std::string &userId, double amount) : Split(userId, amount) {}

bool ExactSplit::validate(double totalAmount, int numUsers) const {
    return amount >= 0.0 && amount <= totalAmount;
}
