#include "concrete_productA.h"
#include <iostream>
#include <memory>
#include <functional>

#include "product_factory.h"


void ConcreteProductA::use() {
    std::cout << "Using Product A\n";
}

bool ConcreteProductA::registered = []() {
    ProductFactory::registerProduct("A", []() { return std::make_shared<ConcreteProductA>(); });
    return true;
}();