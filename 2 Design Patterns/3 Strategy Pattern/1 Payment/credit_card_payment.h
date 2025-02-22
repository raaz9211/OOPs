#ifndef CREDIT_CARD_PAYMENT_H
#define CREDIT_CARD_PAYMENT_H

#include "payment.h"

// Abstract Strategy class

class CreditCardPayment : public Payment{
private:
    std::string card_no;

public:
    CreditCardPayment(std::string card_no) : card_no(card_no) {}
    void pay(int amount);
};

#endif // CREDIT_CARD_PAYMENT_H
