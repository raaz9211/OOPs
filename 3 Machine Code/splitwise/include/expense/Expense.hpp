#pragma once

#include <string>
#include <vector>
#include <memory>

#include "../user/User.hpp"
#include "../split/Split.hpp"
#include "ExpenseType.hpp"

class Expense {
protected:
    std::string id;
    double amount;
    std::shared_ptr<User> paidBy;
    std::vector<std::shared_ptr<Split>> splits;
    ExpenseType type;
public:
    Expense(const std::string& id,
                 double amount,
                 const std::shared_ptr<User>& paidBy,
                 const std::vector<std::shared_ptr<Split>>& splits,
                 ExpenseType type)
    : id(id), amount(amount), paidBy(paidBy), splits(splits), type(type) {}

    virtual ~Expense() = default;

    virtual bool validate() const = 0;

    ExpenseType getType() const {
        return type;
    }

    double getAmount() const {
        return amount;
    }

    std::shared_ptr<User> getPaidBy() const {
        return paidBy;
    }

    const std::vector<std::shared_ptr<Split>>& getSplits() const { 
        return splits; 
    }
    const std::string& getId() const { 
        return id; 
    }
};