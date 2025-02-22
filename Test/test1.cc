#include <iostream>
#include <memory>

class MyClass {
    public:
        void sayHello();    // Function declaration
    };
    
void MyClass::sayHello() {
    std::cout << "Hello from MyClass!" << std::endl;
}

int main() {
    std::unique_ptr<MyClass> t  = std::make_unique<MyClass>();
    t->sayHello();
    return 0;
}
