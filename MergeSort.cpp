#include "MergeSort.hpp"

MergeSort::MergeSort(const std::vector<int>& data) {
    this->data = data;
}

void MergeSort::sort() {
    mergeSort(data, 0, data.size() - 1);
}

void MergeSort::sortAndSave(const std::string& outputFileName) {
    sort();
    std::ofstream outFile(outputFileName, std::ios::app);
    for (const int& num : data) {
        outFile << num << std::endl;
    }
}

void MergeSort::merge(std::vector<int>& data, int left, int mid, int right) {
    int maxIndex = right - left;
    int midIndex = mid - left;
    std::vector<int> arrCopy(maxIndex + 1);

    for (int i = 0; i <= maxIndex; i++)
        arrCopy[i] = data[left + i];

    int i = 0;
    int j = midIndex + 1 + i;
    int k = left;

    while (i <= midIndex && j <= maxIndex) {
        if (arrCopy[i] <= arrCopy[j]) {
            data[k] = arrCopy[i];
            i++;
        }
        else {
            data[k] = arrCopy[j];
            j++;
        }
        k++;
    }

    if (i == midIndex + 1) {
        for (; j <= maxIndex; j++) {
            data[k] = arrCopy[j];
            k++;
        }
    }
    if (j == maxIndex + 1) {
        for (; i <= midIndex; i++) {
            data[k] = arrCopy[i];
            k++;
        }
    }
}

void MergeSort::mergeSort(std::vector<int>& data, int left, int right) {
    if (left < right) {
        int mid = (right + left) / 2;

        mergeSort(data, left, mid);
        mergeSort(data, mid + 1, right);

        merge(data, left, mid, right);
    }
}
