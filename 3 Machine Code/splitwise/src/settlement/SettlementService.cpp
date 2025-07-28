#include "settlement/SettlementService.hpp"

void SettlementService::recordSettlement(const std::shared_ptr<Settlement>& settlement, const std::shared_ptr<BalanceSheet> &balanceSheet) {
    balanceSheet->addDebt(settlement->getFrom()->getId(), settlement->getTo()->getId(), -settlement->getAmount());
    settlementHistory.push_back(settlement);
}

const std::vector<std::shared_ptr<Settlement>> &SettlementService::getSettlement() const {
    return settlementHistory;
}
