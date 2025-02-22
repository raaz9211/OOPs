#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "ISortingStrategy.h"
#include <iostream>

class QuickSort : public ISortingStrategy {
private:
    void quickSort(std::vector<int>& data, int left, int right) {
        if (left >= right) return;
        int pivot = data[right];
        int partitionIndex = left;
        for (int i = left; i < right; ++i) {
            if (data[i] < pivot) {
                std::swap(data[i], data[partitionIndex]);
                ++partitionIndex;
            }
        }
        std::swap(data[partitionIndex], data[right]);
        quickSort(data, left, partitionIndex - 1);
        quickSort(data, partitionIndex + 1, right);
    }

public:
    void sort(std::vector<int>& data) override {
        quickSort(data, 0, data.size() - 1);
        std::cout << "Sorted using Quick Sort\n";
    }
};

#endif // QUICK_SORT_H
