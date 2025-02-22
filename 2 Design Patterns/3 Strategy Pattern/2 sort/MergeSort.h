#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "ISortingStrategy.h"
#include <iostream>

class MergeSort : public ISortingStrategy {
private:
    void merge(std::vector<int>& data, int left, int mid, int right) {
        std::vector<int> leftArr(data.begin() + left, data.begin() + mid + 1);
        std::vector<int> rightArr(data.begin() + mid + 1, data.begin() + right + 1);
        int i = 0, j = 0, k = left;

        while (i < leftArr.size() && j < rightArr.size()) {
            if (leftArr[i] <= rightArr[j]) {
                data[k++] = leftArr[i++];
            } else {
                data[k++] = rightArr[j++];
            }
        }

        while (i < leftArr.size()) data[k++] = leftArr[i++];
        while (j < rightArr.size()) data[k++] = rightArr[j++];
    }

    void mergeSort(std::vector<int>& data, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(data, left, mid);
        mergeSort(data, mid + 1, right);
        merge(data, left, mid, right);
    }

public:
    void sort(std::vector<int>& data) override {
        mergeSort(data, 0, data.size() - 1);
        std::cout << "Sorted using Merge Sort\n";
    }
};

#endif // MERGE_SORT_H
