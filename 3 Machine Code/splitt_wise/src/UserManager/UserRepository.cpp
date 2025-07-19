#include "UserManager/UserRepository.hpp"


bool UserRepository::addUser(std::shared_ptr<User> user) {
    if (user && !userExists(user->getUserId())) {
        users[user->getUserId()] = user;
        return true;
    }
    return false;
}


std::shared_ptr<User> UserRepository::getUserById(const std::string& userId) {
    auto it = users.find(userId);
    return (it != users.end()) ? it->second : nullptr;
}


std::shared_ptr<const User> UserRepository::getUserById(const std::string& userId) const {
    auto it = users.find(userId);
    return (it != users.end()) ? it->second : nullptr;
}


bool UserRepository::updateUser(std::shared_ptr<User> user) {
    if (user && userExists(user->getUserId())) {
        users[user->getUserId()] = user;
        return true;
    }
    return false;
}

bool UserRepository::deleteUser(const std::string& userId) {
    return users.erase(userId) > 0;
}


std::vector<std::shared_ptr<User>> UserRepository::getAllUsers() {
    std::vector<std::shared_ptr<User>> allUsers;
    for (const auto& pair : users) {
        allUsers.push_back(pair.second);
    }
    return allUsers;
}

std::vector<std::shared_ptr<const User>> UserRepository::getAllUsers() const {
    std::vector<std::shared_ptr<const User>> allUsers;
    allUsers.reserve(users.size());  // Optional: for efficiency
    for (const auto& pair : users) {
        allUsers.push_back(pair.second);  // Implicit conversion to shared_ptr<const User>
    }
    return allUsers;
}

std::vector<std::shared_ptr<User>> UserRepository::getUsersByGroup(const std::string& groupId) {
    std::vector<std::shared_ptr<User>> groupUsers;
    for (const auto& pair : users) {
        if (pair.second->isInGroup(groupId)) {
            groupUsers.push_back(pair.second);
        }
    }
    return groupUsers;
}

bool UserRepository::userExists(const std::string& userId) const {
    return users.find(userId) != users.end();
}

size_t UserRepository::getUserCount() const { return users.size(); }

void UserRepository::clearAllUsers() { users.clear(); }

bool UserRepository::isEmpty() const { return users.empty(); }

bool UserRepository::isEmailUnique(const std::string& email, const std::string& excludeUserId) const {
    for (const auto& pair : users) {
        if (pair.first != excludeUserId && pair.second->getEmail() == email) {
            return false;
        }
    }
    return true;
}

std::vector<std::string> UserRepository::getAllUserIds() const {
    std::vector<std::string> ids;
    for (const auto& pair : users) {
        ids.push_back(pair.first);
    }
    return ids;
}