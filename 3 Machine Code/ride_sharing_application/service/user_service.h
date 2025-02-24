#include<iostream>
#include "../database/database.h"


class UserService{
    Database &database = Database::getDatabase();
public:
    bool addUser(std::string username, std::string sex, int age);

};