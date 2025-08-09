#pragma once

#include "../models/Transaction.hpp"
#include "../repository/TransactionRepository.hpp"
#include <memory>
#include <vector>

class TransactionService {
    std::shared_ptr<TransactionRepository> repo;

public:
    TransactionService(std::shared_ptr<TransactionRepository> repo)
    : repo(repo) {}

    void registerTransaction(const std::shared_ptr<Transaction> &transaction) {
        repo->save(transaction);
    }

    std::shared_ptr<Transaction> getTransactionById(int id) {
        return repo->getById(id);
    }

    std::vector<std::shared_ptr<Transaction>> getAllTransactions() {
        return repo->getAll();
    }


    void updateState(int txId, TransactionState newState) {
        auto tx = repo->getById(txId);
        if (tx) tx->setState(newState);
    }
};