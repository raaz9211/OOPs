#ifndef I_SORTING_STRATEGY_H
#define I_SORTING_STRATEGY_H

#include <vector>

// Abstract Strategy (Interface)
class ISortingStrategy {
public:
    virtual void sort(std::vector<int>& data) = 0;
    virtual ~ISortingStrategy() = default;
};

#endif // I_SORTING_STRATEGY_H
