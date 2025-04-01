#pragma once
#include "../entity/order.hpp"

class ExchangeConnector {
    ExchangeConnector() {}
public:
    ExchangeConnector(const ExchangeConnector&) = delete;
    ExchangeConnector& operator=(const ExchangeConnector&) = delete;
    static ExchangeConnector &getExchangeConnectorInstance();
    static void sendOrderToExchnage(string userId, Order *order);
};