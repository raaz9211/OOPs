#include <algorithm>  // For std::find
#include <iostream>   // For displayUserInfo

#include "UserManager/User.hpp"


User::User(const std::string& id, const std::string& name, const std::string& email, 
           const std::string& phone) 
    : userId(id), name(name), email(email), phoneNumber(phone) {}


    const std::string& User::getUserId() const { return userId; }
const std::string& User::getName() const { return name; }
const std::string& User::getEmail() const { return email; }
const std::string& User::getPhoneNumber() const { return phoneNumber; }
const std::vector<std::string>& User::getGroupIds() const { return groupIds; }


void User::setName(const std::string& newName) { name = newName; }
void User::setEmail(const std::string& newEmail) { email = newEmail; }
void User::setPhoneNumber(const std::string& newPhone) { phoneNumber = newPhone; }


void User::addGroup(const std::string& groupId) {
    if (std::find(groupIds.begin(), groupIds.end(), groupId) == groupIds.end()) {
        groupIds.push_back(groupId);
    }
}

bool User::removeGroup(const std::string& groupId) {
    auto it = std::find(groupIds.begin(), groupIds.end(), groupId);
    if (it != groupIds.end()) {
        groupIds.erase(it);
        return true;
    }
    return false;
}


bool User::isInGroup(const std::string& groupId) const {
    return std::find(groupIds.begin(), groupIds.end(), groupId) != groupIds.end();
}

size_t User::getGroupCount() const { return groupIds.size(); }

bool User::isValid() const {
    return !userId.empty() && !name.empty() && !email.empty();
}



void User::displayUserInfo() const {
    std::cout << "User ID: " << userId << ", Name: " << name << ", Email: " << email 
              << ", Phone: " << phoneNumber << std::endl;
}

bool User::operator==(const User& other) const { return userId == other.userId; }
bool User::operator!=(const User& other) const { return !(*this == other); }