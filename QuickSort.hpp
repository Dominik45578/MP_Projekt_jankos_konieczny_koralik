#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include "sortingalg.hpp"

class QuickSort : public SortingAlg {
public:
    QuickSort(const std::vector<int>& data);
    void sort() override;
    void sortAndSave(const std::string& outputFileName);

private:
    void quickSort(int left, int right);
    int partition(int left, int right);
};

#endif // QUICKSORT_HPP
