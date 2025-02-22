#include "credit_card_payment.h"
#include "pay_pal_payment.h"
#include "bit_coin_payment.h"
#include "payment_Context.h"


int main(){
    CreditCardPayment creditCard("1234-5678-9012-3456");
    PayPalPayment payPal("user@example.com");
    BitcoinPayment bitcoin("1A2b3C4d5E6f");

    // Create context with an initial strategy
    PaymentContext context(&creditCard);
    context.executePayment(100);

    context.setStrategy(&payPal);
    context.executePayment(200);

    context.setStrategy(&bitcoin);
    context.executePayment(2);
}