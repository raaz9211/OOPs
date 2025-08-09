#include <iostream>
#include <memory>

#include "models/User.hpp"
#include "repository/InMemoryUserRepository.hpp"
#include "services/UserService.hpp"

#include "models/Transaction.hpp"
#include "repository/InMemoryTransactionRepository.hpp"
#include "services/TransactionService.hpp"

#include "factory/PaymentModeFactory.hpp"

#include "services/PaymentService.hpp"


int main() {
    // auto repo = std::make_shared<InMemoryUserRepository>();
    // auto userService = std::make_shared<UserService>(repo);

    // auto alice = std::make_shared<User>(1, "Alice", "alice@example.com");

    // userService->registerUser(alice);

    // auto found = userService->findUserById(1);

    // if (found) {
    //     std::cout << "User found: " << found->getName() << " (" << found->getEmail() << ")\n";
    // } else {
    //     std::cout << "User not found.\n";
    // }


    // auto repo = std::make_shared<InMemoryTransactionRepository>();
    // auto txService = std::make_shared<TransactionService>(repo);

    // auto tx = std::make_shared<Transaction>(101, 1, 500.0, "UPI"); // id=101, userId=1

    // txService->registerTransaction(tx);


    // auto foundTx = txService->getTransactionById(101);
    // if (foundTx) {
    //     std::cout << "Transaction found: ID=" << foundTx->getId() 
    //             << " User=" << foundTx->getUserId() 
    //             << " Amount=" << foundTx->getAmount() << "\n";
    //     txService->updateState(101, TransactionState::SUCCESS);
    //     std::cout << "Transaction state updated to: " 
    //             << (foundTx->getState() == TransactionState::SUCCESS ? "SUCCESS" : "PENDING") << "\n";
    // } else {
    //     std::cout << "Transaction not found.\n";
    // }


    // auto upiMode = PaymentModeFactory::create("UPI", "alice@upi");
    // if (upiMode && upiMode->initiate(150.0))
    //     std::cout << "UPI payment via factory succeeded\n";

    // auto ccMode = PaymentModeFactory::create("Card", "4111111111111111", "Alice Smith");
    // if (ccMode && ccMode->initiate(500.0))
    //     std::cout << "Credit Card payment via factory succeeded\n";


    auto userRepo = std::make_shared<InMemoryUserRepository>();
    auto txRepo = std::make_shared<InMemoryTransactionRepository>();

    auto alice = std::make_shared<User>(1, "Alice", "alice@example.com");

    auto userService = std::make_shared<UserService>(userRepo);
    userService->registerUser(alice);

    auto paymentService = std::make_shared<PaymentService>(userRepo, txRepo);

    if (paymentService->processPayment(1, 100.0, "UPI", "alice@upi")) {
        std::cout << "Payment via UPI successful!\n";
    } else {
        std::cout << "UPI payment failed.\n";
    }
    // Credit Card payment
    if (paymentService->processPayment(1, 200.0, "Card", "4111111111111111", "Alice Smith")) {
        std::cout << "Payment via CreditCard successful!\n";
    } else {
        std::cout << "CreditCard payment failed.\n";
    }

    return 0;

}