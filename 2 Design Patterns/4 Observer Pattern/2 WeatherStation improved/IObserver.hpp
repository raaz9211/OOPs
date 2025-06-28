#pragma once

class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void update(float temperature) = 0;
};
