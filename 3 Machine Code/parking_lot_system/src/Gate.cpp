#include "models/Gate.hpp"

Gate::Gate(int id, const std::string &name) : gateId(id), gateName(name) {}

int Gate::getId() const
{
    return gateId;
}

std::string Gate::getName() const
{
    return gateName;
}