#pragma once

#include "../models/User.hpp"
#include "../models/Transaction.hpp"

#include "../repository/UserRepository.hpp"
#include "../repository/TransactionRepository.hpp"

#include "../factory/PaymentModeFactory.hpp"


// #include "../"


class PaymentService {
    std::shared_ptr<UserRepository> userRepo;
    std::shared_ptr<TransactionRepository> txRepo;

    int generateTransactionId() {
    static int txId = 2000;
    return txId++;
    }

public :
    PaymentService(const std::shared_ptr<UserRepository> userRepo,
    const std::shared_ptr<TransactionRepository> txRepo)
    : userRepo(userRepo), txRepo(txRepo) {}

    bool processPayment(int userId,
                        double amount,
                        const std::string &modeType,
                        const std::string &detail1,
                        const std::string &detail2 = "") {
        auto user = userRepo->getById(userId);

        if(!user) {
            std::cout << "User not found. \n";
            return false;
        }
        

        auto mode = PaymentModeFactory::create(modeType, detail1, detail2);

        if(!mode) {
            std::cout << "Payment not created. \n";
            return false;
        }

        bool success = mode->initiate(amount);

        auto tx = std::make_shared<Transaction>(
            generateTransactionId(),
            userId,
            amount,
            modeType
        );

        tx->setState(success ? TransactionState::SUCCESS : TransactionState::FAILED);

        txRepo->save(tx);

        return true;
    }
};
