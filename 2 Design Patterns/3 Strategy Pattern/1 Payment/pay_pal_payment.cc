#include "pay_pal_payment.h"

void PayPalPayment::pay(int amount){
    std::cout << "Paid $" << amount << " using PayPal: " << PayPalPayment::email << "\n";
}

