#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

#include "sortingalg.hpp"

class BubbleSort : public SortingAlg {
public:
    BubbleSort(std::string name);
    BubbleSort(const std::vector<int>& data);
    void sort();
    void sortAndSave(const std::string& outputFileName);
};

#endif // BUBBLESORT_HPP
