#ifndef CONCRETE_FACTORY_B_H
#define CONCRETE_FACTORY_B_H

#include "creator.h"
#include "concrete_productB.h"

class ConcreteFactoryB : public Creator {
public:
    std::unique_ptr<Product> createProduct();
};

#endif // CONCRETE_FACTORY_B_H
