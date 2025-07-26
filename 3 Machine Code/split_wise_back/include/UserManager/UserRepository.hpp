#pragma once

#include "User.hpp"
#include <unordered_map>
#include <memory>
#include <vector>
#include <string>


class UserRepository {
private:
    std::unordered_map<std::string, std::shared_ptr<User>> users;
public:
    UserRepository() = default;
    ~UserRepository() = default;

    // Disable copy constructor and assignment (repository should be unique)
    UserRepository(const UserRepository&) = delete;
    UserRepository& operator=(const UserRepository&) = delete;

    // Enable move constructor and assignment
    UserRepository(UserRepository&&) = default;
    UserRepository& operator=(UserRepository&&) = default;



    // CRUD Operations - using shared_ptr
    bool addUser(std::shared_ptr<User> user);
    std::shared_ptr<User> getUserById(const std::string& userId);
    std::shared_ptr<const User> getUserById(const std::string& userId) const;
    bool updateUser(std::shared_ptr<User> user);
    bool deleteUser(const std::string& userId);



    // Query Operations - returning shared_ptr
    std::vector<std::shared_ptr<User>> getAllUsers();
    std::vector<std::shared_ptr<const User>> getAllUsers() const;
    std::vector<std::shared_ptr<User>> getUsersByGroup(const std::string& groupId);
    bool userExists(const std::string& userId) const;
    size_t getUserCount() const;

    // Bulk Operations
    void clearAllUsers();
    bool isEmpty() const;

    // User validation in repository context
    bool isEmailUnique(const std::string& email, const std::string& excludeUserId = "") const;
    std::vector<std::string> getAllUserIds() const;
};