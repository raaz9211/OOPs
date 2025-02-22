#include "BubbleSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "SortingContext.h"
#include <vector>
#include <iostream>

void printArray(const std::vector<int>& data) {
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> data = {9, 7, 5, 3, 1, 2, 4, 6, 8};

    BubbleSort bubbleSort;
    QuickSort quickSort;
    MergeSort mergeSort;

    SortingContext context(&bubbleSort);
    
    std::cout << "Original Data: ";
    printArray(data);
    
    context.executeSort(data);
    printArray(data);

    // Change strategy to QuickSort
    context.setStrategy(&quickSort);
    data = {9, 7, 5, 3, 1, 2, 4, 6, 8};  // Reset data
    context.executeSort(data);
    printArray(data);

    // Change strategy to MergeSort
    context.setStrategy(&mergeSort);
    data = {9, 7, 5, 3, 1, 2, 4, 6, 8};  // Reset data
    context.executeSort(data);
    printArray(data);

    return 0;
}
