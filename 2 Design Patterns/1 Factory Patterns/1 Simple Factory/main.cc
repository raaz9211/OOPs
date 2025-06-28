#include "product_factory.h"


int main(){
    // ||Method 1: Simple Factory Method Implementation||

    // std::unique_ptr<Product> productA = ProductFactory::creatProduct("A");
    // std::unique_ptr<Product> productB = ProductFactory::creatProduct("B");

    // productA->use();
    // productB->use();

    // ||Method 2: Advanced Factory Method Implementation||
    ProductFactory::createProduct("A")->use();
    ProductFactory::createProduct("B")->use();

}

// command to run
// -  g++ main.cc  product_factory.cc concrete_productA.cc  concrete_productB.cc -o program
// - .\program.exe