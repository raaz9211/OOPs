#pragma once

#include <string>
#include <memory>

#include "../user/User.hpp"

class Settlement {
private:
    std::shared_ptr<User> from;
    std::shared_ptr<User> to;
    double amount;
    std::string timestamp;
public:
    Settlement(const std::shared_ptr<User>& from,
               const std::shared_ptr<User>& to,
               double amount,
               const std::string& timestam);

    std::shared_ptr<User> getFrom() const;
    std::shared_ptr<User> getTo() const;
    double getAmount() const;
    const std::string &getTimestamp() const;
};