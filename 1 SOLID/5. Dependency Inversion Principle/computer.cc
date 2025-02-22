#include <iostream>
using namespace std;

// Abstract class (Interface)
class Keyboard
{
public:
    virtual void connect() = 0;
};

// Concrete implementations
class WiredKeyboard : public Keyboard
{
public:
    void connect() override { cout << "Wired Keyboard connected\n"; }
};

class WirelessKeyboard : public Keyboard
{
public:
    void connect() override { cout << "Wireless Keyboard connected\n"; }
};

// High-level module depends on abstraction
class Computer
{
private:
    Keyboard *keyboard; // ✅ Dependency on abstraction, not a concrete class, it is not dependent on any specific keyboard.
public:
    Computer(Keyboard *_keyboard) : keyboard(_keyboard) {} // Inject dependency via constructor
    void useKeyboard() { keyboard->connect(); }
};

int main(){
    WiredKeyboard wiredKeyboard;
    WirelessKeyboard wirelessKeyboard;

    Computer pc1(&wiredKeyboard);
    pc1.useKeyboard();

    Computer pc2(&wiredKeyboard);
    pc2.useKeyboard();

}