#ifndef PRODUCT_FACTORY_H
#define PRODUCT_FACTORY_H

#include "product.h"
#include <memory>
#include <functional>

class ProductFactory
{
    using CreatorFunc = std::function<std::shared_ptr<Product>()>;
    static std::unordered_map<std::string, CreatorFunc> &getRegistry();

public:
    // static std::unique_ptr<Product> creatProduct(const std::string &type);
    static void registerProduct(const std::string &name, CreatorFunc func);
    static std::shared_ptr<Product> createProduct(const std::string &name);
};

#endif // PRODUCT_FACTORY_H