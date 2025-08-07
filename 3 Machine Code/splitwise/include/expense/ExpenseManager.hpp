#pragma once

#include <memory>
#include <vector>

#include "../user/UserRepository.hpp"
#include "../group/GroupRepository.hpp"
#include "Expense.hpp"
#include "../split/Split.hpp"
#include "../balancesheet/BalanceSheet.hpp"
#include "ExpenseFactory.hpp"

class ExpenseManager {
private:
    std::shared_ptr<UserRepository> userRepo;
    std::shared_ptr<GroupRepository> groupRepo;
    std::shared_ptr<BalanceSheet> balanceSheet;
    std::vector<std::shared_ptr<Expense>> expenses;

public:
    ExpenseManager(std::shared_ptr<UserRepository> userRepo,
                   std::shared_ptr<GroupRepository> groupRepo,
                    std::shared_ptr<BalanceSheet> balanceSheet);
    
    void addExpense(ExpenseType type,
                const std::string& id,
                double amount,
                const std::string& paidById,
                const std::vector<std::shared_ptr<Split>>& splits,
                const std::string& groupId = "");

    void showBalances() const;
};