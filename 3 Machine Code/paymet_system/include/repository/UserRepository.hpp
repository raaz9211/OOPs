#pragma once

#include "../models/User.hpp"
#include <memory>
#include <vector>
#include <optional>
#include <unordered_map>

class UserRepository {

public:
    virtual void save(const std::shared_ptr<User> &user) = 0;
    virtual std::shared_ptr<User> getById(int id) = 0;
    virtual std::vector<std::shared_ptr<User>> getAll() = 0;
    virtual ~UserRepository() = default;
};