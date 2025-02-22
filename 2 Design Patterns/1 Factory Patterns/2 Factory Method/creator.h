#ifndef CREATOR_H
#define CREATOR_H

#include "product.h"
#include <memory>

class Creator {
public:
    virtual std::unique_ptr<Product> createProduct() = 0;  // Factory Method
    virtual ~Creator() = default;
};

#endif // CREATOR_H