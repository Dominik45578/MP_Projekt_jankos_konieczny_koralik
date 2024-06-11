#ifndef SORTINGALG_HPP
#define SORTINGALG_HPP

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

class SortingAlg {
public:
    virtual ~SortingAlg() = default;
    virtual void sort() = 0;
    virtual void sortAndSave(const std::string& outputFileName) = 0;
    const std::vector<int> getData();

protected:
    int &operator[](int index);
    const int &operator[](int index) const;
    friend std::ostream& operator<<(std::ostream& os, const SortingAlg& alg);
    std::vector<int> data;
};

#endif // SORTINGALG_HPP
