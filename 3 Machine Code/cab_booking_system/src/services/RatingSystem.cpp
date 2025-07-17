#include "services/RatingSystem.hpp"



void RatingSystem::addRating(const Rating &rating) {
    userRatings[rating.getToUserId()].push_back(rating);
}

double RatingSystem::getAverageRating(const std::string& userId) const {
    auto it = userRatings.find(userId);

    if (it == userRatings.end()) {
        return 0.0;
    }

    double sum = 0.0;
    for (const auto& rating : it->second) {
        sum += rating.getScore();
    }
    return sum / it->second.size();
}

std::vector<Rating> RatingSystem::getAllRatings(const std::string& userId) const {
    auto it = userRatings.find(userId);

    if (it != userRatings.end()) {
        return it->second;
    }
    return {};
}
