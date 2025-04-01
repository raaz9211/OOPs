#pragma once
#include "order_validator.hpp"
#include "order_execuationer.hpp"


class OrderManager {
    OrderValidator *validator;
    OrderExecuationer * execuationer;
public:
    OrderManager() {
        validator = new OrderValidator();
        execuationer = new OrderExecuationer();
    }
    void placeOrder(string userId, Order *order);
};