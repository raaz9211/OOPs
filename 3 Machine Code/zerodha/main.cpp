#include "service/order_manager.hpp"
#include "common/common.hpp"
#include "entity/user.hpp"


int main() {
    User *user = new User("rajat");

    Stock *stock = new Stock("TCS", 100, EXCHANGE::NSE);

    Order *order = new Order(TRANSACTION_TYPE::BUY, ORDER_TYPE::LIMIT, 1100, 20, stock, EXCHANGE::NSE);

    OrderManager *orderManager = new OrderManager();

    orderManager->placeOrder("rajat", order);

    return 0;
}
