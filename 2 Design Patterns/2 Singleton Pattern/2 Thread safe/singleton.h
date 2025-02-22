#ifndef SINGLETON_H
#define SINGLETON_H


#include<iostream>

class Singleton {
private:

    // Private constructor to prevent instantiation
    Singleton() { std::cout << "Singleton Instance Created\n"; }

public:
    // Delete copy constructor and assignment operator
    // +---------------------------------------------------------------------
    // | Singleton s1 = Singleton::getInstance();  // ✅ Allowed
    // | Singleton s2 = s1;  // ❌ Compile error: Copy constructor is deleted!
    // | s2 = Singleton::getInstance();  // ❌ Compile error: Assignment operator is deleted!
    // +---------------------------------------------------------------------
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Public static methord to get the single instance
    static Singleton &getInstance();
    
    void someMethord();
};

#endif //SINGLETON_H