#pragma once
#include <iostream>
using namespace std;

enum class TRANSACTION_TYPE {
    BUY,
    SELL
};

enum class ORDER_TYPE {
    MARKET,
    LIMIT
};

enum class EXCHANGE {
    NSE,
    BSE
};


enum class ORDER_STATUS {
    OPEN,
    PARTIALLY_DONE,
    DONE,
    CANCELLED
};
