#ifndef  CONCRETE_PRODUCT_B_H
#define CONCRETE_PRODUCT_B_H

#include "product.h"

class ConcreteProductB : public Product{
// ||Method 1: Simple Factory Method Implementation||
private:
    static bool registered;
public:
    void use();
};

#endif // CONCRETE_PRODUCT_B_H