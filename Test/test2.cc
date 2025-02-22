#include<iostream>

int &fun(){
    static int c = 18;
    return c;
}
int main(){
    int a = 5;
    int &b = a;

    a = 8;
    
    std::cout <<b;

    int &f1 = fun();
    std::cout << f1;
}