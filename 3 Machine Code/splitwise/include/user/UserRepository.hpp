#pragma once

#include <memory>
#include <vector>
#include <string>

#include "User.hpp"


class UserRepository {
public:
    virtual ~UserRepository() = default;
    
    virtual bool addUser(const std::shared_ptr<User>& user) = 0;
    virtual std::shared_ptr<User> getUserById(const std::string& userId) const = 0;
    virtual std::vector<std::shared_ptr<User>> getAllUsers() const = 0;
};