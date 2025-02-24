#ifndef USER_H
#define USER_H

#include <string>

class User{
private:
    std::string username;
    std::string sex;
    int age;

public:
    void setUsername(std::string username){
        this->username = username;
    }

    void setSex(std::string sex){
        this->sex = sex;
    }

    void setAge(int age){
        this->age = age;
    }

    std::string getUsername() const {
        return this->username;
    }

    std::string getSex() const {
        return this->sex;
    }

    int getAge() const {
        return this->age;
    }

    // bool operator==(const User& user) const
    // {
    //     return this->username == user.username;
    // }
 
};

#endif // USER_H