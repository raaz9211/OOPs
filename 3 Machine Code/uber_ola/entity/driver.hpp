#pragma once
#include "../common/common.hpp"

class Driver {
    string name;
    bool avail;
    RATING rating;

public:
    Driver(string name, RATING rating) : name(name), rating(rating), avail(false) {}
        
    void updateAvail(bool avail) {
        this->avail = avail;
    }
    string getDriverName(){
        return this->name;
    }

    RATING getRating(){
        return this->rating;
    }
};