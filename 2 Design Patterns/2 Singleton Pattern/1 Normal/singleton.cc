#include "singleton.h"

// Initialize the static instance pointer to nullptr
Singleton* Singleton::instance = nullptr;

Singleton* Singleton::getInstance() {
    if(instance == nullptr){
        instance = new Singleton();  // Create instance if it doesn't exist
    }
    return instance;
}