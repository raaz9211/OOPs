#include "concrete_productB.h"
#include <iostream>
#include <memory>
#include <functional>

#include "product_factory.h"

void ConcreteProductB::use() {
    std::cout << "Using Product B\n";
}

bool ConcreteProductB::registered = []() {
    ProductFactory::registerProduct("B", []() { return std::make_shared<ConcreteProductB>(); });
    return true;
}();