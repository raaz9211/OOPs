#include "product_factory.h"


int main(){
    std::unique_ptr<Product> productA = ProductFactory::creatProdyct("A");
    std::unique_ptr<Product> productB = ProductFactory::creatProdyct("B");

    productA->use();
    productB->use();

}

// command to run
// -  g++ main.cc  product_factory.cc concrete_productA.cc  concrete_productB.cc -o program
// - .\program.exe