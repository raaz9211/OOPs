#pragma once
#include "../entity/user.hpp"
#include <unordered_map>


class System {
    static unordered_map<string, User*> users;
public:
    static void addUser(string userId, User *user);
    static User *getUser(string userId);
    
};