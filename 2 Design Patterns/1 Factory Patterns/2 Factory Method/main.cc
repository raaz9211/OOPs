#include "concrete_factoryA.h"
#include "concrete_factoryb.h"
#include <memory>

int main(){
    std::unique_ptr<Creator>factoryA  = std::make_unique<ConcreteFactoryA>();
    std::unique_ptr<Creator>factoryB  = std::make_unique<ConcreteFactoryB>();

    std::unique_ptr<Product> productA = factoryA->createProduct();
    std::unique_ptr<Product> productB = factoryB->createProduct();

    productA->use();
    productB->use();
    
    
}

// command -  g++ *.cc -o program