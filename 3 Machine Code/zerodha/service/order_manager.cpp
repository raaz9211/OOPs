#include "order_manager.hpp"


void OrderManager::placeOrder(string userId, Order *order){
    if(OrderManager::validator->validaateOrder(userId, order)){
        execuationer->placeOrder(userId, order);
    }
}