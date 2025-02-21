#include <iostream>
using namespace std;

class WiredKeyboard {
public:
    void connect() {cout << "Wired Keyboard connected\n";}
};

class Computer {
private:
    WiredKeyboard wiredKeyboard;
public:
    void useKeyboard() {  wiredKeyboard.connect(); }
};

int main(){
    Computer computer;
    computer.useKeyboard();
}