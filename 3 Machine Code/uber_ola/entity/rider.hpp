#pragma once
#include "../common/common.hpp"

class Rider {
    string name;
    RATING rating;
public:
    Rider(string name, RATING rating) : name(name), rating(rating) {}
    
    string getRiderName(){
        return this->name;
    }

    RATING getRating(){
        return this->rating;
    }
};