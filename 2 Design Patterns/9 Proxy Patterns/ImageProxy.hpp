#pragma once
#include "Image.hpp"
#include "RealImage.hpp"
#include <memory>

class ImageProxy : public Image {
    std::unique_ptr<RealImage> realImage;
    std::string filename;

public:
    ImageProxy(const std::string& file) : filename(file), realImage(nullptr) {}

    void display() override {
        if (!realImage) {
            realImage = std::make_unique<RealImage>(filename);
        }
        realImage->display();
    }
};