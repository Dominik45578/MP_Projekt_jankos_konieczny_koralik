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

protected:
    void print();
    friend class Menu;
    int &operator[](int index);
    const int &operator[](int index) const;
    friend std::ostream& operator<<(std::ostream& os, const SortingAlg& alg);
    std::vector<int> data;
    std::string name;
};

#endif // SORTINGALG_HPP
