#ifndef PAYMENT_CONTEXT_H
#define PAYMENT_CONTEXT_H

#include "payment.h"
#include <memory>


class PaymentContext {
private:
    Payment *payment;
public:
    PaymentContext(Payment *payment) : payment(payment) {};

    void setStrategy(Payment *new_payment){
        payment = new_payment;
    }

    void executePayment(int amount){
        payment->pay(amount);
    }
};

#endif // PAYMENT_CONTEXT_H