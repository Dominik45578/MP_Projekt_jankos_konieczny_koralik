#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

#include "sortingalg.hpp"

class HeapSort : public SortingAlg {
public:
    HeapSort(const std::vector<int>& data);
    void sort() override;
    void sortAndSave(const std::string& outputFileName) override;

private:
    void heapSort(std::vector<int>& data, int size);
    void heapify(std::vector<int>& data, int size, int i);
    void swap(std::vector<int>& data, int indexa, int indexb);
};

#endif // HEAPSORT_HPP
