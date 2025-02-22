#ifndef BITCOIN_PAYMENT_H
#define BITCOIN_PAYMENT_H

#include "payment.h"

// Abstract Strategy class

class BitcoinPayment  : public Payment{
private:
    std::string wallet_address;

public:
BitcoinPayment (std::string wallet_address) : wallet_address(wallet_address) {}
    void pay(int amount);
};

#endif // BITCOIN_PAYMENT_H
