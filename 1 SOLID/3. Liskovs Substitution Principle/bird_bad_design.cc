#include <iostream>
using namespace std;

class Bird
{
public:
    virtual void fly() { cout << "Bird is flying\n"; }
};

class Penguin : public Bird
{
public:
    void fly() override { throw logic_error("Penguins can't fly!"); }
};

int main()
{
    Penguin penguin;
    penguin.fly();
}