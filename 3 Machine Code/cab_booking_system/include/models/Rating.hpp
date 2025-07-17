#pragma once
#include <string>

class Rating {
private:
    std::string fromUserId;
    std::string toUserId;
    double score; // between 1.0 to 5.0
public:
    Rating(const std::string& from, const std::string& to, double score);

    std::string getFromUserId() const;
    std::string getToUserId() const;
    double getScore() const;
};