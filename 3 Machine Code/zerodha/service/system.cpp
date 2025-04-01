#include "system.hpp"

unordered_map<string, User*> System::users;

void System::addUser(string userId, User *user) {
    System::users[userId] = user;
}


User *System::getUser(string userId) {
    return System::users[userId];
}