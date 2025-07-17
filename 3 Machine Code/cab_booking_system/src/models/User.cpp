#include "models/User.hpp"


User::User(const std::string &id, const std::string &name) 
    : id(id), name(name) {}



std::string User::getId() const {
    return id;
}



std::string User::getName() const {
    return name;
}