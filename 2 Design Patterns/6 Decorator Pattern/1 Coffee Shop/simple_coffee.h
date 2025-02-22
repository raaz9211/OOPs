#ifndef SIMPLECOFFEE_H
#define SIMPLECOFFEE_H

#include "coffee.h"

class SimpleCoffee : public Coffee{
public:
    double cost() const {
        return 5.0;  // Base cost of simple coffee
    }

    std::string getDescription() const {
        return "Simple Coffee";
    }
};

#endif // SIMPLECOFFEE_H
