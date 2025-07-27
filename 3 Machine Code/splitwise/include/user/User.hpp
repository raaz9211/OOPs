#pragma once

#include <string>
#include <stdexcept>

class User
{
private:
    std::string id;
    std::string name;
    std::string email;
    std::string phone;

public:
    User(const std::string &_id,
         const std::string &_name,
         const std::string &_email,
         const std::string &_phone)
        : id(_id), name(_name), email(_email), phone(_phone)
    {
        if (id.empty())
        {
            throw std::invalid_argument("User ID required");
        }
    }

    const std::string& getId() const { return id; }
    const std::string& getName() const { return name; }
    const std::string& getEmail() const { return email; }
    const std::string& getPhone() const { return phone; }

    bool operator==(const User & user) const {
        return this->id == user.getId();
    }
};