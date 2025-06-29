#pragma once
#include <iostream>

class OldAudioPlayerDevice  {
public:
    void plugAndPlay() {
        std::cout << "[OldDevice] Playing through 3.5mm jack 🎧\n";
    }
};