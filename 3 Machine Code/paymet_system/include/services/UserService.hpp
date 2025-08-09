#pragma once

#include "../models/User.hpp"
#include "../repository/UserRepository.hpp"
#include <memory>
#include <vector>

class UserService {
    std::shared_ptr<UserRepository> repo;

public:
    UserService(std::shared_ptr<UserRepository> repo)
    : repo(repo) {}

    void registerUser(const std::shared_ptr<User> &user) {
        repo->save(user);
    }

    std::shared_ptr<User> findUserById(int id) {
        return repo->getById(id);
    }

    std::vector<std::shared_ptr<User>> getAllUsers() {
        return repo->getAll();
    }
};