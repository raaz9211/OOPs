#include "settlement/Settlement.hpp"


Settlement::Settlement(const std::shared_ptr<User>& from,
               const std::shared_ptr<User>& to,
               double amount,
               const std::string& timestamp) 
               : from(from), to(to), amount(amount), timestamp(timestamp) {}

std::shared_ptr<User> Settlement::getFrom() const {
    return from;
}

std::shared_ptr<User> Settlement::getTo() const {
    return to;
}

double Settlement::getAmount() const {
    return amount;
}

const std::string &Settlement::getTimestamp() const {
    return timestamp;
}