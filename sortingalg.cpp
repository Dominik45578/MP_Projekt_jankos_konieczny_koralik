#include "sortingalg.hpp"

int& SortingAlg::operator[](int index) {
    return data.at(index); 
}

const int& SortingAlg::operator[](int index) const {
    return data.at(index); 
}
std::ostream& operator<<(std::ostream& os, const SortingAlg& alg) {
    for (const int& num : alg.data) {
        os << num << " ";
    }
    return os;
}

const std::vector<int> SortingAlg::getData() {
    return this->data;
}