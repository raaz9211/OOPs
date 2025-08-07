#pragma once

#include "Expense.hpp"

class ExactExpense : public Expense {
public:
    ExactExpense(const std::string& id,
                 double amount,
                 const std::shared_ptr<User>& paidBy,
                 const std::vector<std::shared_ptr<Split>>& splits,
                 const std::string& groupId = "");
    bool validate() const override;

};