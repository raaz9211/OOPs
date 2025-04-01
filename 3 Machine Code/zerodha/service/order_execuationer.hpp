#pragma once
#include "../entity/order.hpp"
#include "../repository/exchange_connector.hpp"


class OrderExecuationer{
public:
    void placeOrder(string userId, Order *order){
        ExchangeConnector &exchangeConnector = ExchangeConnector::getExchangeConnectorInstance();
        exchangeConnector.sendOrderToExchnage(userId, order);
    }   
};