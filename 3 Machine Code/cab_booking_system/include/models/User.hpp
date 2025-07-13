#pragma once

#include <string>


class User {
protected:
    std::string id;
    std::string name;
public:
    User(const std::string &id, const std::string &name);
    virtual ~User() = default;

    std::string getId() const;
    std::string getName() const;

};