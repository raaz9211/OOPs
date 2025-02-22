#include "concrete_factoryB.h"

std::unique_ptr<Product> ConcreteFactoryB::createProduct(){
    return std::make_unique<ConcreteProductB>();
}

