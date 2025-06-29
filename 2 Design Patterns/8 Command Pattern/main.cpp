#include <memory>

#include "RemoteControl.hpp"
#include "TV.hpp"
#include "TurnOnCommand.hpp"
#include "TurnOffCommand.hpp"


int main() {
    TV tv;

    std::shared_ptr<TurnOnCommand> onCommand = std::make_shared<TurnOnCommand>(&tv);
    std::shared_ptr<TurnOffCommand> offCommand = std::make_shared<TurnOffCommand>(&tv);

    RemoteControl remote;

    remote.setCommand(std::move(onCommand));
    remote.pressButton();  // Output: [TV] is now ON.   

    remote.setCommand(std::move(offCommand));
    remote.pressButton();  // Output: [TV] is now OFF.
}