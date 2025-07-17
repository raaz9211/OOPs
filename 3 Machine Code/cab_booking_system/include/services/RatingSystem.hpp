#pragma once

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>
#include "models/Rating.hpp"


class RatingSystem {
private:
    std::unordered_map<std::string, std::vector<Rating>> userRatings;
public:
    void addRating(const Rating &rating);
    double getAverageRating(const std::string& userId) const;
    std::vector<Rating> getAllRatings(const std::string& userId) const;

};