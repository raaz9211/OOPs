#pragma once

#include "TransactionRepository.hpp"
#include <unordered_map>


class InMemoryTransactionRepository : public TransactionRepository {

    std::unordered_map<int, std::shared_ptr<Transaction>> transactions;

public:
    void save(const std::shared_ptr<Transaction> &transaction) override {
        transactions[transaction->getId()] = transaction;
    }

    std::shared_ptr<Transaction> getById(int id) override {
        auto transactionIt = transactions.find(id);

        if (transactionIt != transactions.end()) {
            return transactionIt->second;
        }

        return nullptr;
    }

    std::vector<std::shared_ptr<Transaction>> getAll() {
        std::vector<std::shared_ptr<Transaction>> allTransactions;

        for(const auto &transaction : transactions) {
            allTransactions.push_back(transaction.second);
        }

        return allTransactions;

    }

};


