
#include "exchange_connector.hpp"

ExchangeConnector &ExchangeConnector::getExchangeConnectorInstance() {
    static ExchangeConnector exchangeConnectorInstance;
    return exchangeConnectorInstance;
}

void ExchangeConnector::sendOrderToExchnage(string userId, Order *order) {
    cout << "Order is sent to Exchange, Congrate \n";
}