#ifndef SORTING_CONTEXT_H
#define SORTING_CONTEXT_H

#include "ISortingStrategy.h"

class SortingContext {
private:
    ISortingStrategy* strategy;
public:
    SortingContext(ISortingStrategy* strategy) : strategy(strategy) {}

    void setStrategy(ISortingStrategy* newStrategy) {
        strategy = newStrategy;
    }

    void executeSort(std::vector<int>& data) {
        strategy->sort(data);
    }
};

#endif // SORTING_CONTEXT_H
