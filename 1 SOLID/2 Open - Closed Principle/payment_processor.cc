#include <iostream>

class PaymentProcessor {
public:
    virtual void processPayment(double amount) = 0; 
};

class CreditCardPaymentProcessor : public PaymentProcessor {
public:
    void processPayment(double amount){
        std::cout << "Processing credit card payment of $" << amount << std::endl;
    }
};

class PayPalPaymentProcessor : public PaymentProcessor {
public:
    void processPayment(double amount){
        std::cout << "Processing Pay Pal payment of $" << amount << std::endl;
    }
};

int main(){
    CreditCardPaymentProcessor creditCardPaymentProcessor;
    PayPalPaymentProcessor payPalPaymentProcessor;

    creditCardPaymentProcessor.processPayment(10);
    payPalPaymentProcessor.processPayment(100);

}