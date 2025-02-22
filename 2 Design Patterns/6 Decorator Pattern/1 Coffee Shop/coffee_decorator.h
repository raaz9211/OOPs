#ifndef COFFEE_DECORATOR_H
#define COFFEE_DECORATOR_H

#include "coffee.h"

// Abstract Decorator (Wrapper)
class CoffeeDecorator : public Coffee {
protected:
    Coffee *coffee; // Wrapped coffee object

public:
    CoffeeDecorator(Coffee *coffee) : coffee(coffee) {}

    virtual double cost() const {
        return coffee->cost(); // Delegate cost calculation
    }

    virtual std::string getDescription() const {
        return coffee->getDescription();
    }
    
    virtual ~CoffeeDecorator() {
        delete coffee;  // Free memory
    }
};

#endif // COFFEE_DECORATOR_H
