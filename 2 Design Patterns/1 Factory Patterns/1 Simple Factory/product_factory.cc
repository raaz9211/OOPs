#include "product_factory.h"

// ||Method 1: Simple Factory Method Implementation||
// #include "concrete_productA.h"
// #include "concrete_productB.h"
//
// // Simple Factory Method Implementation
// // This factory creates products based on the type provided.
// // It returns a unique pointer to the created product, allowing for polymorphic behavior.
// // If the type does not match any known product, it returns a nullptr.
// std::unique_ptr<Product> ProductFactory::creatProduct(const std::string &type)
// {
//     if (type == "A")
//     {
//         return std::make_unique<ConcreteProductA>();
//     }
//     if (type == "B")
//     {
//         return std::make_unique<ConcreteProductB>();
//     }
//     return nullptr;
// }

// ||Method 2: Advanced Factory Method Implementation||

//  Advanced: Registration-Based (Plugin-Style) Factory
//  This factory uses a registry to map product names to creation functions.
//  It allows for dynamic registration of new product types, enabling extensibility without modifying the factory code.
std::unordered_map<std::string, ProductFactory::CreatorFunc> &ProductFactory::getRegistry()
{
    static std::unordered_map<std::string, CreatorFunc> registry;
    return registry;
}

void ProductFactory::registerProduct(const std::string &name, CreatorFunc func)
{
    getRegistry()[name] = func;
}

std::shared_ptr<Product> ProductFactory::createProduct(const std::string &name)
{
    auto it = getRegistry().find(name);
    if (it != getRegistry().end())
    {
        return it->second();
    }
    return nullptr;
}
