#ifndef PRODUCT_FACTORY_H
#define PRODUCT_FACTORY_H

#include "product.h"
#include <memory>

class ProductFactory {
public:
    static std::unique_ptr<Product> creatProdyct(const std::string& type);

};


#endif // PRODUCT_FACTORY_H