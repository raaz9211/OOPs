#include <iostream>
using namespace std;

class Bird
{
public:
    virtual void fly() { cout << "Bird is flying\n"; }
};

class FlyingBird : public Bird
{
public:
    virtual void fly() { cout << "Flying bird is flying\n"; }
};

class Sparrow : public FlyingBird
{
public:
    void fly() { cout << "Sparrow is flying\n"; }
};

class Penguin : public Bird
{
};

int main()
{
    Bird *birdSparrow = new Sparrow();
    Bird *birdPenguin = new Penguin();

    birdSparrow->fly();
    birdPenguin->fly();
}
