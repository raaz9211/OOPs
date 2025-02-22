#include "singleton.h"
#include <thread>


// Function that each thread will run
void threadFunction() {
    Singleton& s = Singleton::getInstance();
    s.someMethord();
}

int main(){
    Singleton &s1 = Singleton::getInstance();
    Singleton &s2 = Singleton::getInstance();

    s1.someMethord();
    s2.someMethord();

    // Checking if both instances are the same
    if (&s1 == &s2) {
        std::cout << "Both instances are the same (Singleton works!)\n";
    } else {
        std::cout << "Different instances (Singleton failed!)\n";
    }



    // Create multiple threads to test thread safety
    std::thread t1(threadFunction);
    std::thread t2(threadFunction);
    std::thread t3(threadFunction);

    t1.join();
    t2.join();
    t3.join();

    return 0;


}

// command -  g++ *.cc -o program