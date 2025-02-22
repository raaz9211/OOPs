#ifndef SUGARDECORATOR_H
#define SUGARDECORATOR_H

#include "coffee_decorator.h"

// Concrete Decorator: Adds Sugar
class SugarDecorator : public CoffeeDecorator{
public:
    SugarDecorator(Coffee *coffee) : CoffeeDecorator(coffee) {}

    double cost() const {
        return coffee->cost() + 0.5; // Extra cost for Sugar
    }

    std::string getDescription() const override {
        return coffee->getDescription() + ", Sugar";
    }
};

#endif //SUGARDECORATOR_H