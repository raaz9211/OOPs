#pragma once
#include <iostream>
#include "Image.hpp"

class RealImage : public Image {
    std::string filename;

    void loadFromDisk() const {
        std::cout << "[RealImage] Loading " << filename << " from disk...\n";
    }

public:
    RealImage(const std::string& file) : filename(file) {
        loadFromDisk();
    }

    void display()  override {
        std::cout << "[RealImage] Displaying " << filename << "\n";
    }
};