#include <iostream>

// Class for baking bread
class BreadBaker {
public:
    void bakeBread(){
        std::cout << "Baking high-quality bread..."<< std::endl;;
    }
};

class InventoryManager {
public:
    void manageInventory() {
        std::cout << "Managing inventory..." << std::endl;
    }
};

class SupplyOrder {
public:
    void orderSuplies(){
        std::cout << "Ordering supplies..." << std::endl;
    }
};

class CustomerService {
public:
    void cleanBakery(){
        std::cout << "Cleaning the bakery..." << std::endl;
    }

};

int main(){
    BreadBaker baker;
    InventoryManager inventory_manager;
    SupplyOrder supply_order;
    CustomerService customer_service;
    BreadBaker bread_baker;

    baker.bakeBread();
    inventory_manager.manageInventory();
    supply_order.orderSuplies();
    customer_service.cleanBakery();
    bread_baker.bakeBread();
}
