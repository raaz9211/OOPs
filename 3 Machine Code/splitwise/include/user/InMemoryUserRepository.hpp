#pragma once

#include <unordered_map>

#include "UserRepository.hpp"

class InMemoryUserRepository : public UserRepository
{

private:
    std::unordered_map<std::string, std::shared_ptr<User>> users;

public:
    bool addUser(const std::shared_ptr<User> &user) override
    {
        if (!user || users.count(user->getId()) > 0)
        {
            return false;
        }

        users[user->getId()] = user;
        return true;
    }

    std::shared_ptr<User> getUserById(const std::string &userId) const override
    {
        auto it = users.find(userId);
        if (it != users.end())
        {
            return it->second;
        }

        return nullptr;
    }

    std::vector<std::shared_ptr<User>> getAllUsers() const override
    {
        std::vector<std::shared_ptr<User>> results;
        for (const auto &pair : users){
            results.push_back(pair.second);
        }
        return results;
    }
};