#include "models/Rating.hpp"

Rating::Rating(const std::string& from, const std::string& to, double score)
    : fromUserId(from), toUserId(to), score(score) {}

std::string Rating::getFromUserId() const {
    return fromUserId;
}

std::string Rating::getToUserId() const {
    return toUserId;
}

double Rating::getScore() const {
    return score;
}
