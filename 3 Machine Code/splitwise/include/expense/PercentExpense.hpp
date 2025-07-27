#pragma once

#include "Expense.hpp"

class PercentExpense : public Expense {
public:
    PercentExpense(const std::string& id,
                 double amount,
                 const std::shared_ptr<User>& paidBy,
                 const std::vector<std::shared_ptr<Split>>& splits);
    bool validate() const override;

};