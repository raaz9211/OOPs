#ifndef CONCRETE_PRODUCT_A_H
#define CONCRETE_PRODUCT_A_H

#include "product.h"

class ConcreteProductA : public Product{
// ||Method 1: Simple Factory Method Implementation||
private:
    static bool registered;
public:
    void use() override;

};

#endif // CONCRETE_PRODUCT_A_H