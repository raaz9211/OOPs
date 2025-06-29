#pragma once
#include "Adaptee.hpp"
#include "Target.hpp"

class AudioAdapter : public AudioTarget {
private:
    OldAudioPlayerDevice* oldDevice;

public:
    explicit AudioAdapter(OldAudioPlayerDevice* device) : oldDevice(device) {}

    void playAudio() override {
        std::cout << "[Adapter] Converting to compatible format...\n";
        oldDevice->plugAndPlay();
    }
};