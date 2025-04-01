#pragma once

#include "../entity/order.hpp"
#include "system.hpp"

class OrderValidator {
public:
    bool validaateOrder(string userId, Order *order);
};