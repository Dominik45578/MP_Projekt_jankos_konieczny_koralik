#include "BubbleSort.hpp"

BubbleSort::BubbleSort(std::string name)
{
    this->name = name;
}

BubbleSort::BubbleSort(const std::vector<int>& data) {
    this->data = data;
}

void BubbleSort::sort() {
    bool swapped;
    int size = data.size();
    for (int i = 0; i < size - 1; ++i) {
        swapped = false;
        for (int j = 0; j < size - 1 - i; ++j) {
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void BubbleSort::sortAndSave(const std::string& outputFileName) {
    sort();
    std::ofstream outFile(outputFileName, std::ios::app);
    //outFile << "<< Posortowana tablica | ilosc : " << data.size() << std::endl;
    for (const int& num : data) {
        outFile << num << std::endl;
        std::cout << num << " ";
    }
    outFile << std::endl;
    std::cout << std::endl;
}
