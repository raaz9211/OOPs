#include "singleton.h"


int main(){
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    s1->someMethord();
    s2->someMethord();

    // Checking if both instances are the same
    if (s1 == s2) {
        std::cout << "Both instances are the same (Singleton works!)\n";
    } else {
        std::cout << "Different instances (Singleton failed!)\n";
    }

}

// command -  g++ *.cc -o program