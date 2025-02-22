#ifndef CONCRETE_FACTORY_A_H
#define CONCRETE_FACTORY_A_H

#include "creator.h"
#include "concrete_productA.h"

class ConcreteFactoryA : public Creator {
public:
    std::unique_ptr<Product> createProduct();
};

#endif // CONCRETE_FACTORY_A_H
