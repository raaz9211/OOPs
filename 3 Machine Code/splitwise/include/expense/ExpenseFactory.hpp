#pragma once

#include "EqualExpense.hpp"
#include "ExactExpense.hpp"
#include "PercentExpense.hpp"
#include "ExpenseType.hpp"


class ExpenseFactory {
public:
    static std::shared_ptr<Expense> creatExpense(
        ExpenseType type,
        const std::string& id,
        double amount,
        const std::shared_ptr<User>& paidBy,
        const std::vector<std::shared_ptr<Split>>& splits) {
            switch (type) {
                case ExpenseType::EQUAL:
                    return std::make_shared<EqualExpense>(id, amount, paidBy, splits);
                case ExpenseType::EXACT:
                    return std::make_shared<ExactExpense>(id, amount, paidBy, splits);
                case ExpenseType::PERCENT:
                    return std::make_shared<PercentExpense>(id, amount, paidBy, splits);
                default:
                    return nullptr;
            }
        }
};