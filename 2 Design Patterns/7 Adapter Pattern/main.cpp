#include <memory>
#include "Adapter.hpp"
#include "Adaptee.hpp"
#include "Target.hpp"

int main() {
    // Create an instance of the old audio player device
    auto oldDevice = std::make_unique<OldAudioPlayerDevice>();

    // Create an adapter for the old device
    AudioAdapter adapter(oldDevice.get());

    // Use the adapter to play audio
    adapter.playAudio();

    return 0;
}