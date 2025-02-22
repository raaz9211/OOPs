#include <iostream>
#include <string>
// Abstract Component
class Coffee {
public:
    virtual double cost() const = 0;
    virtual std::string getDescription() const = 0;
    virtual ~Coffee() = default;
};

// Concrete Component
class SimpleCoffee : public Coffee {
public:
    double cost() const override { return 5.0; }
    std::string getDescription() const override { return "Simple Coffee"; }
};

// Abstract Decorator
class CoffeeDecorator : public Coffee {
protected:
    Coffee* coffee; // Wrapped coffee object
public:
CoffeeDecorator() {}
    CoffeeDecorator(Coffee* c) : coffee(c) {
        std::cout << "CoffeeDecorator Constructor\n";
    }
};

// Concrete Decorator (Adds Milk)
class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(Coffee* c)  { 
        std::cout << "MilkDecorator Constructor\n";
    }

    double cost() const override { return coffee->cost() + 2.0; } // Adds milk cost
    std::string getDescription() const override { return coffee->getDescription() + ", Milk"; }
};


int main() {
    Coffee* myCoffee = new SimpleCoffee();  // Base coffee
    myCoffee = new MilkDecorator(myCoffee); // Wrap it with sugar

    std::cout << "Cost: " << myCoffee->cost() << std::endl; // Cost: 6.0
    std::cout << "Description: " << myCoffee->getDescription() << std::endl; // "Simple Coffee, Sugar"

    delete myCoffee; // Clean up
    return 0;
}
