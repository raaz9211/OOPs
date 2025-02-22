#ifndef MILK_DECORATOR_H
#define MILK_DECORATOR_H

#include "coffee_decorator.h"

// Concrete Decorator: Adds Milk
class MilkDecorator : public CoffeeDecorator{
public:
    MilkDecorator(Coffee *coffee) : CoffeeDecorator(coffee) {}

    double cost() const {
        return coffee->cost() + 1.5; // Extra cost for milk
    }

    std::string getDescription() const override {
        return coffee->getDescription() + ", Milk";
    }
};

#endif //MILK_DECORATOR_H