#pragma once
#include "../common/common.hpp"
#include "stock.hpp"


class Order {
    TRANSACTION_TYPE transactionType;
    ORDER_TYPE orderType;
    double price;
    int quantity;
    Stock *_stock;
    EXCHANGE exchange;

public:
    Order(TRANSACTION_TYPE transactionType, ORDER_TYPE orderType, double price, int quantity, Stock *_stock, EXCHANGE exchange) :
    transactionType(transactionType), orderType(orderType), price(price), quantity(quantity), _stock(_stock), exchange(exchange) {}

    TRANSACTION_TYPE getTransactionType() {
        return transactionType;
    }
};

