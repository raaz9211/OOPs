#include <iostream>
#include <stdexcept>

#include "expense/ExpenseManager.hpp"


ExpenseManager::ExpenseManager(std::shared_ptr<UserRepository> userRepo,
                               std::shared_ptr<GroupRepository> groupRepo)
    : userRepo(userRepo), groupRepo(groupRepo),
      balanceSheet(std::make_shared<BalanceSheet>()) {}

    
void ExpenseManager::addExpense(ExpenseType type,
            const std::string& id,
            double amount,
            const std::string& paidById,
            const std::vector<std::shared_ptr<Split>>& splits) {
    auto paidBy = userRepo->getUserById(paidById);
    
    if(!paidBy) {
        throw std::invalid_argument("Payer not found");
    }

    auto expense = ExpenseFactory::creatExpense(type, id, amount, paidBy, splits);

    if(!expense || !expense->validate()){
        throw std::runtime_error("Invalid expense splits");
    }

    expenses.push_back(expense);

    for(const auto &split : splits) {
        if(split->getUser()->getId() != paidById) {
            balanceSheet->addDebt(split->getUser()->getId(), paidById, split->getAmount());
        }
    }
}

void ExpenseManager::showBalances() const {
    std::vector<std::shared_ptr<User>> users = userRepo->getAllUsers();

    for(auto &user : users) {
        auto owed = balanceSheet->getUserBalance(user->getId());

        for(auto &kv : owed) {
            if (kv.second > 0) {
                std::cout << user->getName() << " owes "
                          << userRepo->getUserById(kv.first)->getName()
                          << ": " << kv.second << std::endl;
            }
        }
    }
}