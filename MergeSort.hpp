#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include "sortingalg.hpp"

class MergeSort : public SortingAlg {
public:
    MergeSort(std::string name);
    MergeSort(const std::vector<int>& data);
    void sort() override;
    void sortAndSave(const std::string& outputFileName) override;

private:
    void mergeSort(std::vector<int>& data, int left, int right);
    void merge(std::vector<int>& data, int left, int mid, int right);
};

#endif // MERGESORT_HPP
