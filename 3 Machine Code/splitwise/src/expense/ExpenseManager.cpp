#include <iostream>
#include <stdexcept>

#include "expense/ExpenseManager.hpp"


ExpenseManager::ExpenseManager(std::shared_ptr<UserRepository> userRepo,
                               std::shared_ptr<GroupRepository> groupRepo,
                            std::shared_ptr<BalanceSheet> balanceSheet)
    : userRepo(userRepo), groupRepo(groupRepo),
      balanceSheet(balanceSheet) {}

    
void ExpenseManager::addExpense(ExpenseType type,
            const std::string& id,
            double amount,
            const std::string& paidById,
            const std::vector<std::shared_ptr<Split>>& splits,
            const std::string& groupId) {

    auto paidBy = userRepo->getUserById(paidById);
    
    if(!paidBy) {
        throw std::invalid_argument("Payer not found");
    }


    std::shared_ptr<Group> group = nullptr;
    if(!groupId.empty()) {
        group = groupRepo->getGroupById(groupId);
        if(!group) {
            throw std::runtime_error("Group not found");
        }

        for(const auto &split : splits) {
            bool inGroup = false;
            for(const auto &member : group->getAllMembers()) {
                if(split->getUser()->getId() == member->getId()) {
                    inGroup = true;
                    break;
                }
            }

            if(!inGroup) {
                throw std::runtime_error("User is not in Group.");
            }
        }
    }

    auto expense = ExpenseFactory::createExpense(type, id, amount, paidBy, splits, groupId);

    if(!expense || !expense->validate()){
        throw std::runtime_error("Invalid expense splits");
    }

    expenses.push_back(expense);

    if (!groupId.empty()) {
        group->addExpense(expense);
    }

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