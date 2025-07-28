#pragma once

#include <vector>

#include "Settlement.hpp"
#include "../balancesheet/BalanceSheet.hpp"

class SettlementService {
private:
    std::vector<std::shared_ptr<Settlement>> settlementHistory;
public:
    void recordSettlement(const std::shared_ptr<Settlement>& settlement, const std::shared_ptr<BalanceSheet> &balanceSheet);

    const std::vector<std::shared_ptr<Settlement>> &getSettlement() const;
};