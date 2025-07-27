#include <cmath>

#include "expense/ExactExpense.hpp"

ExactExpense::ExactExpense(const std::string& id,
                 double amount,
                 const std::shared_ptr<User>& paidBy,
                 const std::vector<std::shared_ptr<Split>>& splits)
                 : Expense(id, amount, paidBy, splits, ExpenseType::EXACT) {}

bool ExactExpense::validate() const {
    if(splits.empty()) {
        return false;
    }    

    double sum = 0.0;

    for (auto &split : splits) {
        sum += split->getAmount();
    }

    return std::abs(sum - amount) < 1e-6;
}

