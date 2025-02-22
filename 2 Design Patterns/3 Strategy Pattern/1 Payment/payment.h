#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>

// Abstract Strategy class

class Payment{
public:
    virtual void pay(int amount) = 0; // Pure virtual function
    virtual ~Payment() = default;
};

#endif // PAYMENT_H
