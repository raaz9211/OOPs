#include <iostream>

#include "user/InMemoryUserRepository.hpp"
#include "group/InMemoryGroupRepository.hpp"
#include "expense/ExpenseManager.hpp"
#include "split/EqualSplit.hpp"
#include "settlement/Settlement.hpp"
#include "settlement/SettlementService.hpp"
#include "balancesheet/BalanceSheet.hpp"
#include "group/GroupService.hpp"

int main() {
    // std::shared_ptr<UserRepository> userRepo = std::make_shared<InMemoryUserRepository>();

    // auto user1 = std::make_shared<User>("u1", "Alice", "alice@example.com", "9876543210");
    // auto user2 = std::make_shared<User>("u2", "Bob", "bob@example.com", "9876543211");

    // userRepo->addUser(user1);
    // userRepo->addUser(user2);


    // auto groupRepo = std::make_shared<InMemoryGroupRepository>();

    // auto group = std::make_shared<Group>("g1", "trip");

    // group->addMember(user1);
    // group->addMember(user2);
    // groupRepo->addGroup(group);


    // std::cout << "Group: " << group->getName() << "\nMembers:\n";
    // for (const auto& member : group->getAllMembers()) {
    //     std::cout << member->getName() << std::endl;
    // }


    // phase 2

    auto userRepo = std::make_shared<InMemoryUserRepository>();
    auto groupRepo = std::make_shared<InMemoryGroupRepository>();
    auto balanceSheet = std::make_shared<BalanceSheet>();
    auto groupService = std::make_shared<GroupService>(groupRepo, userRepo);


    auto alice = std::make_shared<User>("u1", "Alice", "alice@example.com", "9876543210");
    auto bob   = std::make_shared<User>("u2", "Bob",   "bob@example.com",   "9876543211");

    userRepo->addUser(alice);
    userRepo->addUser(bob);

    auto group = groupService->createGroup("g1", "Trip");
    groupService->addMember("g1", "u1");
    groupService->addMember("g1", "u2");


    ExpenseManager manager(userRepo, groupRepo, balanceSheet);


    std::vector<std::shared_ptr<Split>> splits = {
        std::make_shared<EqualSplit>(alice, 50),
        std::make_shared<EqualSplit>(bob, 50)
    };

    manager.addExpense(ExpenseType::EQUAL, "e1", 100, "u1", splits, "g1");

    std::cout << "Balances BEFORE settlement:" << std::endl;
    manager.showBalances();


    auto settlementService = std::make_shared<SettlementService>();

    auto settlement = std::make_shared<Settlement>(bob, alice, 30, "2025-07-27T23:00:00");
    
    settlementService->recordSettlement(settlement, balanceSheet);
    
    std::cout << "\nBalances AFTER settlement:" << std::endl;
    manager.showBalances();

    // Display settlement history
    std::cout << "\nSettlement History:" << std::endl;
    for (const auto& s : settlementService->getSettlement()) {
        std::cout << s->getFrom()->getName() << " paid " << s->getTo()->getName()
                  << " amount: " << s->getAmount() << " at " << s->getTimestamp() << std::endl;
    }


    std::cout << "\nExpenses for group '" << group->getName() << "'\n";
    for (const auto& exp : group->getExpenses()) {
        std::cout << "Expense ID: " << exp->getId()
                  << ", Amount: " << exp->getAmount()
                  << ", Paid by: " << exp->getPaidBy()->getName() << std::endl;
    }


    // // phase 3
    // auto alice = std::make_shared<User>("u1", "Alice", "alice@example.com", "9876543210");
    // auto bob = std::make_shared<User>("u2", "Bob", "bob@example.com", "9876543211");

    // Settlement s(bob, alice, 70.0, "2025-07-27T15:05:00");
    // std::cout << s.getFrom()->getName() << " paid " << s.getTo()->getName()
    //           << " amount: " << s.getAmount() << " at " << s.getTimestamp() << std::endl;



    return 0;
}
