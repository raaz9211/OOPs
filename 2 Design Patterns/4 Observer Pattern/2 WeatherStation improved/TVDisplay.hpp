#pragma once

#include <iostream>
#include "IObserver.hpp"

class TVDisplay : public IObserver {
public:
    void update(float temperature) override {
        std::cout << "[TVDisplay] Temperature updated: " << temperature << "°C\n";
    }
};

