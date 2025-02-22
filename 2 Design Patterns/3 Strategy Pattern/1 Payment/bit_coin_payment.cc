#include "bit_coin_payment.h"

void BitcoinPayment::pay(int amount){
    std::cout << "Paid $" << amount << " using Bitcoin Wallet: " << BitcoinPayment::wallet_address << "\n";
}

