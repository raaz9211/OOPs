#include <cmath>

#include "balancesheet/BalanceSheet.hpp"


double BalanceSheet::getBalance(const std::string& owedBy, const std::string& owedTo) const {
    auto it = balances.find({owedBy, owedTo});

    return it != balances.end() ? it->second : 0.0;
}

void BalanceSheet::addDebt(const std::string &owedBy, const std::string &owedTo, double amount) {
    if(owedBy == owedTo) {
        return;
    }

    balances[{owedBy, owedTo}] += amount;
    balances[{owedTo, owedBy}] -= amount;
}

std::map<std::string, double> BalanceSheet::getUserBalance(const std::string &userId) const {
    std::map<std::string, double> result;
    for (const auto &balance : balances) {
        if (balance.first.first == userId && std::abs(balance.second) > 1e-6) {
            result[balance.first.second] = balance.second;
        }
    }
    return result;

}