#include<iostream>
#include "../entity/user.h"
#include "user_service.h"


bool UserService::addUser(std::string username, std::string sex, int age){
    if(UserService::database.table.count(username)){
        std::cout << "Username is already exist." << std::endl;
        return false;
    } else {   
        User *user = new User();
        user->setUsername(username);
        user->setSex(sex);
        user->setAge(age);
        UserService::database.table[username] = {user, {}};   
        return true;
    }
}