#include <cmath>

#include "expense/PercentExpense.hpp"

PercentExpense::PercentExpense(const std::string& id,
                 double amount,
                 const std::shared_ptr<User>& paidBy,
                 const std::vector<std::shared_ptr<Split>>& splits)
                 : Expense(id, amount, paidBy, splits, ExpenseType::PERCENT) {}

bool PercentExpense::validate() const {
    if(splits.empty()) {
        return false;
    }    

    double percentSum = 0.0;

    for (auto &split : splits) {
        percentSum += split->getPercent();
    }

    return std::abs(percentSum - 100.0) < 1e-6;
}

