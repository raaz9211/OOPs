#pragma once

class AudioTarget {
public:
    virtual ~AudioTarget() = default;
    virtual void playAudio() = 0;
};
