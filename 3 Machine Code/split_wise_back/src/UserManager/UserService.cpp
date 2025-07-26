#include <regex>  // For email validation

#include "UserManager/UserService.hpp"


UserService::UserService() : userRepository(std::make_shared<UserRepository>()) {}

UserService::UserService(std::shared_ptr<UserRepository> repository) 
    : userRepository(std::move(repository)) {}



std::shared_ptr<User> UserService::createUser(const std::string& name, const std::string& email, 
                                             const std::string& phone) {
    if (!validateUserData(name, email, phone)) return nullptr;
    
    std::string id = generateUserId();
    auto user = std::make_shared<User>(id, name, email, phone);
    
    if (userRepository->addUser(user)) {
        return user;
    }
    return nullptr;
}

std::shared_ptr<User> UserService::getUserById(const std::string& userId) {
    return userRepository->getUserById(userId);
}

std::shared_ptr<const User> UserService::getUserById(const std::string& userId) const {
    return userRepository->getUserById(userId);
}

bool UserService::updateUser(std::shared_ptr<User> user) {
    if (!user || !validateUserData(user->getName(), user->getEmail(), user->getPhoneNumber())) {
        return false;
    }
    return userRepository->updateUser(user);
}

bool UserService::deleteUser(const std::string& userId) {
    return userRepository->deleteUser(userId);
}

std::vector<std::shared_ptr<User>> UserService::getAllUsers() {
    return userRepository->getAllUsers();
}

std::vector<std::shared_ptr<const User>> UserService::getAllUsers() const {
    return  static_cast<const UserRepository*>(userRepository.get())->getAllUsers();;  // Calls const version
}

std::vector<std::shared_ptr<User>> UserService::getUsersByGroup(const std::string& groupId) {
    return userRepository->getUsersByGroup(groupId);
}

std::shared_ptr<User> UserService::getUserByEmail(const std::string& email) {
    for (auto user : getAllUsers()) {
        if (user->getEmail() == email) return user;
    }
    return nullptr;
}

size_t UserService::getTotalUsers() const {
    return userRepository->getUserCount();
}

bool UserService::validateUserData(const std::string& name, const std::string& email, 
                                  const std::string& phone) const {
    return isValidName(name) && isValidEmail(email) && isValidPhone(phone);
}

bool UserService::isEmailAvailable(const std::string& email, const std::string& excludeUserId) const {
    return userRepository->isEmailUnique(email, excludeUserId);
}


bool UserService::addUserToGroup(const std::string& userId, const std::string& groupId) {
    auto user = getUserById(userId);
    if (user) {
        user->addGroup(groupId);
        return updateUser(user);
    }
    return false;
}


bool UserService::removeUserFromGroup(const std::string& userId, const std::string& groupId) {
    auto user = getUserById(userId);
    if (user && user->removeGroup(groupId)) {
        return updateUser(user);
    }
    return false;
}

std::vector<std::shared_ptr<User>> UserService::getUsersInGroup(const std::string& groupId) {
    return getUsersByGroup(groupId);
}


bool UserService::userExists(const std::string& userId) const {
    return userRepository->userExists(userId);
}

void UserService::displayAllUsers() const {
    for (auto user : getAllUsers()) {
        user->displayUserInfo();
    }
}

std::vector<std::string> UserService::getAllUserIds() const {
    return userRepository->getAllUserIds();
}

std::string UserService::generateUserId() const {
    // Simple ID generation (in real LLD, use UUID)
    static int counter = 0;
    return "U" + std::to_string(++counter);
}


bool UserService::isValidEmail(const std::string& email) const {
    static std::regex emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return std::regex_match(email, emailPattern);
}

bool UserService::isValidName(const std::string& name) const {
    return !name.empty() && name.length() <= 50;
}

bool UserService::isValidPhone(const std::string& phone) const {
    return phone.empty() || (phone.length() >= 10 && phone.length() <= 15);
}