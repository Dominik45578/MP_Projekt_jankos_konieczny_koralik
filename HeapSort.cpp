#include "HeapSort.hpp"

HeapSort::HeapSort(const std::vector<int>& data) {
    this->data = data;
}

void HeapSort::sort() {
    heapSort(data, data.size());
}

void HeapSort::sortAndSave(const std::string& outputFileName) {
    sort();
    std::ofstream outFile(outputFileName, std::ios::app);
    for (const int& num : data) {
        outFile << num << std::endl;
    }
}

void HeapSort::swap(std::vector<int>& data, int indexa, int indexb) {
    int t = data[indexb];
    data[indexb] = data[indexa];
    data[indexa] = t;
}

void HeapSort::heapify(std::vector<int>& data, int size, int i) {
    int largestSon = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && data[l] > data[largestSon])
        largestSon = l;

    if (r < size && data[r] > data[largestSon])
        largestSon = r;

    if (largestSon != i) {
        swap(data, i, largestSon);
        heapify(data, size, largestSon);
    }
}

void HeapSort::heapSort(std::vector<int>& data, int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(data, size, i);

    for (int i = size - 1; i >= 0; i--) {
        swap(data, 0, i);
        heapify(data, i, 0);
    }
}
