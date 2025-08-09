#pragma once

#include "TransactionState.hpp"
#include <string>
#include <chrono>
#include <memory>

class Transaction {
    int id;
    int userId;
    double amount;
    std::string paymentModeType;
    TransactionState state;
    std::chrono::system_clock::time_point createdAt;
public:
    Transaction(int id, int userId, double amount, const std::string paymentModeType)
    : id(id), 
      userId(userId),
      amount(amount),
      paymentModeType(paymentModeType),
      state(state),
      createdAt(std::chrono::system_clock::now()) {}

    void setState(TransactionState newState) { state = newState; }
    TransactionState getState() const { return state; }

    int getId() const { return id; }
    int getUserId() const { return userId; }
    double getAmount() const { return amount; }
    const std::string& getPaymentModeType() const { return paymentModeType; }
    const std::chrono::system_clock::time_point& getCreatedAt() const { return createdAt; }
};