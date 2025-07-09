#pragma once

#include <string>

class City {
private:
    int id;
    std::string name;

public:
    City(int id, const std::string &name) : id(id), name(name) {}

    int  getId() const {
        return id;
    }

    const std::string &getName() const {
        return name;
    }
};