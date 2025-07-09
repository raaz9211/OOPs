#pragma once

#include <string>

class User {
private:
    int id;
    std::string name;
public:
    User(int id, const std::string &name) : id(id), name(name) {}

    int getId() const {
        return id;
    }

    const std::string &getName() const {
        return name;
    }
};