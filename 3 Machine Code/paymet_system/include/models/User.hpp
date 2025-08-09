#pragma once

#include <string>
#include <vector>
#include <memory>

class PaymentMode;

class User {
    int id;
    std::string name;
    std::string email;
    std::vector<std::shared_ptr<PaymentMode>> paymentMethods;

    public:
    User(int id,
    std::string name,
    std::string email) 
    : id(id), name(name), email(email) {}

    void addPaymentMethod(std::shared_ptr<PaymentMode> method) {
        paymentMethods.push_back(method);
    }
    
    const std::vector<std::shared_ptr<PaymentMode>>& getPaymentMethods() const {
        return paymentMethods;
    }

    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getEmail() const { return email; }
};