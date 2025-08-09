#pragma once

#include "../models/Transaction.hpp"
#include <memory>
#include <vector>

class TransactionRepository {
public:
    virtual void save(const std::shared_ptr<Transaction>& tx) = 0;
    virtual std::shared_ptr<Transaction> getById(int id) = 0;
    virtual std::vector<std::shared_ptr<Transaction>> getAll() = 0;
    virtual ~TransactionRepository() = default;
};