#pragma once

#include <iostream>
#include "IObserver.hpp"

class PhoneDisplay : public IObserver {
public:
    void update(float temperature) override {
        std::cout << "[PhoneDisplay] Temperature updated: " << temperature << "°C\n";
    }
};

