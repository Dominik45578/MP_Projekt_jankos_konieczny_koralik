#include "QuickSort.hpp"

QuickSort::QuickSort(const std::vector<int>& data) {
    this->data = data;
}

void QuickSort::sort() {
    quickSort(0, data.size() - 1);
}

void QuickSort::sortAndSave(const std::string& outputFileName) {
    sort();
    std::ofstream outFile(outputFileName, std::ios::app);
    for (const int& num : data) {
        outFile << num << std::endl;
    }
}

void QuickSort::quickSort(int left, int right) {
    if (left < right) {
        int pivotIndex = partition(left, right);
        quickSort(left, pivotIndex - 1);
        quickSort(pivotIndex + 1, right);
    }
}

int QuickSort::partition(int left, int right) {
    int pivot = data[right];
    int i = left - 1;

    for (int j = left; j < right; ++j) {
        if (data[j] <= pivot) {
            ++i;
            std::swap(data[i], data[j]);
        }
    }
    std::swap(data[i + 1], data[right]);
    return i + 1;
}
    