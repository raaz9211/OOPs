#pragma once
#include "Command.hpp"
#include "TV.hpp"

class TurnOnCommand : public Command {
private:
    TV *tv;
public:
    explicit TurnOnCommand(TV *tv) : tv(tv) {}
    void execute() override {
        tv->turnOn();
    }
};