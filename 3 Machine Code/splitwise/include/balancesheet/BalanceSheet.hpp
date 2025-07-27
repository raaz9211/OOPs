#pragma once

#include <map>
#include <string>

class BalanceSheet {
private:
    std::map<std::pair<std::string, std::string>, double> balances;

public:
    double getBalance(const std::string& owedBy, const std::string& owedTo) const;

    void addDebt(const std::string &owedBy, const std::string &owedTo, double amount);

    std::map<std::string, double> getUserBalance(const std::string &userId) const;
};