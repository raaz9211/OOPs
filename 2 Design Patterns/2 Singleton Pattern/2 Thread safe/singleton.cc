#include "singleton.h"
#include <thread>

void Singleton::someMethord(){
    std::cout << "Singleton Method Called by Thread"
    << std::this_thread::get_id() << "\n";
}

Singleton &Singleton::getInstance() {
    static Singleton instance; // Thread-safe since C++11
    return instance;
}