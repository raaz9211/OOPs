#pragma once

#include "../modes/PaymentMode.hpp"
#include "../modes/Card.hpp"
#include "../modes/UPI.hpp"

#include <memory>
#include <string>

class PaymentModeFactory {
public:
    static std::shared_ptr<PaymentMode> create(const std::string &type,const std::string& primary, const std::string& secondary = "") {
        if(type == "UPI") {
            return std::make_shared<UPI>(primary);
        }
        if (type == "Card") {
            return std::make_shared<Card>(primary, secondary);
        }
        
        return nullptr;
    }
}; 