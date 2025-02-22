#ifndef PAY_PAL_PAYMENT_H
#define PAY_PAL_PAYMENT_H

#include "payment.h"

// Abstract Strategy class

class PayPalPayment : public Payment{
private:
    std::string email;

public:
    PayPalPayment(std::string email) : email(email) {}
    void pay(int amount);
};

#endif // PAY_PAL_PAYMENT_H
