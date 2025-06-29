#pragma once
#include <memory>
#include <iostream>
#include "Command.hpp"

class RemoteControl {
private:
    std::shared_ptr<Command> command;
public:
    void setCommand(std::shared_ptr<Command> cmd) {
        command = std::move(cmd);
    } 

    void pressButton() {
        if (command) {
            command->execute();
        } else {
            std::cout << "No command set!" << std::endl;
        }
    }
};