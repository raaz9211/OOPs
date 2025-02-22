#include "concrete_factoryA.h"

std::unique_ptr<Product> ConcreteFactoryA::createProduct(){
    return std::make_unique<ConcreteProductA>();
}

