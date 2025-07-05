#pragma once

#include <string>

class Gate {
protected:
    int gateId;
    std::string gateName;
public:
    Gate(int id, const std::string &name);
    virtual ~Gate() = default;

    int getId() const;
    std::string getName() const;

};