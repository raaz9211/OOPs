#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Screen.hpp"
#include "City.hpp"

class Theatre {
private:
    int id;
    std::string name;
    std::shared_ptr<City> city;
    std::vector<std::shared_ptr<Screen>> screens;
public:
    Theatre(int id, std::string name, std::shared_ptr<City> city) 
        : id(id), name(name), city(city) {}

    int getId() const {
        return id;
    }

    const std::string &getName() const {
        return name;
    }


    const std::shared_ptr<City> &getCity() const {
        return city;
    }

    const std::vector<std::shared_ptr<Screen>>& getScreens() const {
        return screens;
    }

    void addScreen(const std::shared_ptr<Screen>& screen) {
        screens.push_back(screen);
    }
};