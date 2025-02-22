#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>

class Product {
public:
    // virtual → Ensures proper cleanup when deleting an object through a base class pointer.
    // ~Product() → Destructor for the Product class.
    // = default; → Tells the compiler to generate the default destructor.
    virtual void use() = 0;
    virtual ~Product() = default;
};

#endif // PRODUCT_H