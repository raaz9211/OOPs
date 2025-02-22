#ifndef COFFEE_H
#define COFFEE_H

#include <string>

// Abstract Componect
class Coffee {
public:
    virtual double cost() const = 0;
    virtual std::string getDescription() const = 0;
    virtual ~Coffee() = default;

};

#endif // COFFEE_H
