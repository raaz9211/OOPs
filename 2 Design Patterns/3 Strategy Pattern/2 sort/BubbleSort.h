#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "ISortingStrategy.h"
#include <iostream>

class BubbleSort : public ISortingStrategy {
public:
    void sort(std::vector<int>& data) override {
        int n = data.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (data[j] > data[j + 1]) {
                    std::swap(data[j], data[j + 1]);
                }
            }
        }
        std::cout << "Sorted using Bubble Sort\n";
    }
};

#endif // BUBBLE_SORT_H
