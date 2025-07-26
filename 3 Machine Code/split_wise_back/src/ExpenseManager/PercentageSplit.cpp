#include "ExpenseManager/PercentageSplit.hpp"
#include "Utils/Constants.hpp"



PercentageSplit::PercentageSplit(const std::string &userId, double amount, double percentage) : Split(userId, amount), percentage(percentage) {}

bool PercentageSplit::validate(double totalAmount, int /*numUsers*/) const {
    if(percentage < 0.0 || percentage > 100.0) {
        return false;
    }

    double calcAmount = totalAmount * (percentage / 100.0);
    return std::abs(amount - calcAmount) < Constants::EPSILON;
}

double PercentageSplit::getPercentage() const { return percentage; }
void PercentageSplit::setPercentage(double newPercentage) { percentage = newPercentage; }
