#pragma once
#include "Command.hpp"
#include "TV.hpp"

class TurnOffCommand : public Command {
private:
    TV *tv;
public:
    explicit TurnOffCommand(TV *tv) : tv(tv) {}
    void execute() override {
        tv->turnOff();
    }
};