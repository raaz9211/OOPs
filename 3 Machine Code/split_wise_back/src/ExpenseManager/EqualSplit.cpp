#include "ExpenseManager/EqualSplit.hpp"
#include "Utils/Constants.hpp"



EqualSplit::EqualSplit(const std::string &userId, double amount) : Split(userId, amount) {}

bool EqualSplit::validate(double totalAmount, int numUsers) const {
    if(numUsers <= 0) {
        return false;
    }

    double expectedAmount = totalAmount / numUsers;
    return std::abs(amount - expectedAmount) < Constants::EPSILON;
}
