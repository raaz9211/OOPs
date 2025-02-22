#include "credit_card_payment.h"

void CreditCardPayment::pay(int amount){
    std::cout << "Paid $" << amount << " using Credit Card: " << CreditCardPayment::card_no << "\n";
}

