#include "product_factory.h"
#include "concrete_productA.h"
#include "concrete_productB.h"


std::unique_ptr<Product> ProductFactory::creatProdyct(const std::string &type)
{
    if (type == "A")
    {
        return std::make_unique<ConcreteProductA>();
    }
    if (type == "B")
    {
        return std::make_unique<ConcreteProductB>();
    }
    return nullptr;
}
