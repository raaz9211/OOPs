#pragma once

#include "User.hpp"
#include "UserRepository.hpp"
#include <memory>
#include <string>
#include <vector>


class UserService {
private:
    std::shared_ptr<UserRepository> userRepository;

     // Helper methods for validation
    bool isValidEmail(const std::string& email) const;
    bool isValidName(const std::string& name) const;
    bool isValidPhone(const std::string& phone) const;
    std::string generateUserId() const;
public:
    UserService();
    explicit UserService(std::shared_ptr<UserRepository> repository);

    // Disable copy constructor and assignment
    UserService(const UserService&) = delete;
    UserService& operator=(const UserService&) = delete;

    // Enable move constructor and assignment
    UserService(UserService&&) = default;
    UserService& operator=(UserService&&) = default;

    std::shared_ptr<User> createUser(const std::string& name, const std::string& email, 
                                   const std::string& phone = "");
    std::shared_ptr<User> getUserById(const std::string& userId);
    std::shared_ptr<const User> getUserById(const std::string& userId) const;
    bool updateUser(std::shared_ptr<User> user);
    bool deleteUser(const std::string& userId);


    // User Query Operations - returning shared_ptr vectors
    std::vector<std::shared_ptr<User>> getAllUsers();
    std::vector<std::shared_ptr<const User>> getAllUsers() const;
    std::vector<std::shared_ptr<User>> getUsersByGroup(const std::string& groupId);
    std::shared_ptr<User> getUserByEmail(const std::string& email);
    size_t getTotalUsers() const;


     // User Validation
    bool validateUserData(const std::string& name, const std::string& email, 
                         const std::string& phone = "") const;
    bool isEmailAvailable(const std::string& email, 
                         const std::string& excludeUserId = "") const;

     // Group Management Integration - using shared_ptr
    bool addUserToGroup(const std::string& userId, const std::string& groupId);
    bool removeUserFromGroup(const std::string& userId, const std::string& groupId);
    std::vector<std::shared_ptr<User>> getUsersInGroup(const std::string& groupId);


    // Utility Operations
    bool userExists(const std::string& userId) const;
    void displayAllUsers() const;
    std::vector<std::string> getAllUserIds() const;
};