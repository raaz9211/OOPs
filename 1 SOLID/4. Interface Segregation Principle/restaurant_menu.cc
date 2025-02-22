#include <iostream>
#include <vector>
using namespace std;

class IVegetarianMenu
{
public:
    virtual vector<string> getVegetarianItems() = 0;
};

class INonVegetarianMenu
{
public:
    virtual vector<string> getNonVegetarianMenu() = 0;
};

class IDrinkMenu
{
public:
    virtual vector<string> getDrinkMenu() = 0;
};

class VegetarianMenu : public IVegetarianMenu
{
public:
    vector<string> getVegetarianItems() override
    {
        return {"Vegetable Curry", "Paneer Tikka", "Salad"};
    }
};

class NonVegetarianMenu : public INonVegetarianMenu
{
public:
    vector<string> getNonVegetarianMenu() override
    {
        return {"Chicken Curry", "Fish Fry", "Mutton Biryani"};
    }
};

class DrinkMenu : public IDrinkMenu
{
public:
    vector<string> getDrinkMenu() override
    {
        return {"Water", "Soda", "Juice"};
    }
};

void displayVegetarianMenu(IVegetarianMenu *menu)
{
    cout << "Vegetarian Menu:\n";
    for (const auto &item : menu->getVegetarianItems())
    {
        cout << "- " << item << endl;
    }
}

void displayVegetarianMenu(INonVegetarianMenu *menu)
{
    cout << "Non-Vegetarian Menu:\n";
    for (const auto &item : menu->getNonVegetarianMenu())
    {
        cout << "- " << item << endl;
    }
}

int main(){
    VegetarianMenu vegetarianMenu;
    NonVegetarianMenu nonVegetarianMenu;
    DrinkMenu drinkMenu;

    displayVegetarianMenu(&vegetarianMenu);
    displayVegetarianMenu(&nonVegetarianMenu);

}