#include "simple_coffee.h"
#include "milk_decorator.h"
#include "sugar_decorator.h"
#include <iostream>


int main() {
    // Step 1: Start with a basic coffee
    Coffee *myCoffee = new SimpleCoffee();
    std::cout << myCoffee->getDescription() << " - Cost: $" << myCoffee->cost() << "\n";


    // Step 2: Add Milk
    myCoffee = new MilkDecorator(myCoffee);
    std::cout << myCoffee->getDescription() << " - Cost: $" << myCoffee->cost() << "\n";

    // Step 3: Add Sugar
    myCoffee = new SugarDecorator(myCoffee);
    std::cout << myCoffee->getDescription() << " - Cost: $" << myCoffee->cost() << "\n";
}
