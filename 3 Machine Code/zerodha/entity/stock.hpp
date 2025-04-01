#pragma once
#include "../common/common.hpp"

class Stock {
    EXCHANGE exchange;
    string name;
    double price;
public:
    Stock(string name, int price, EXCHANGE exchange) :
    name(name), price(price), exchange(exchange) {}
};