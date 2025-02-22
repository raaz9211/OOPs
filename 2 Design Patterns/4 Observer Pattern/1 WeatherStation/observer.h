#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
public:
    virtual void update(float temperature) = 0; // Pure virtual function
    virtual ~Observer() = default;
};

#endif // OBSERVER_H
