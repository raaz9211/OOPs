#include "order_validator.hpp"


bool OrderValidator::validaateOrder(string userId, Order *order) {
    User *user = System::getUser(userId);
    if(order->getTransactionType() == TRANSACTION_TYPE::BUY){
        cout << "Checking if user has fund to buy \n";
    }
    else {
        cout << "Checking if user has stock to sell \n";
    }

    cout << "Assume has made valid order request \n";
    return true;
}