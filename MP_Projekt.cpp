#include "sortingalg.hpp"
#include "MergeSort.hpp"
#include "HeapSort.hpp"
#include "BubbleSort.hpp"
#include "QuickSort.hpp"
#include "menu.hpp"
#include <vector>
#include <random>
#include <iostream>

std::vector<int> generateRandomVector(int size = 15, int min = -100, int max = 100) {
    std::vector<int> vec(size);
    std::random_device rand;
    std::mt19937 mt(rand());
    std::uniform_int_distribution<int> dist(min, max);
    for (int& num : vec) {
        num = dist(mt);
    }
    return vec;
}

void sortWithAlgorithm(SortingAlg* algorithm) {
    algorithm->sort();
    std::cout<<algorithm<<std::endl;
    delete algorithm;
}

int main() {
    Menu menu;

    menu.addOption("MergeSort", []() {
        std::vector<int> data = generateRandomVector();
        sortWithAlgorithm(new MergeSort(data));
        });

    menu.addOption("HeapSort", []() {
        std::vector<int> data = generateRandomVector();
        sortWithAlgorithm(new HeapSort(data));
        });

    menu.addOption("BubbleSort", []() {
        std::vector<int> data = generateRandomVector();
        sortWithAlgorithm(new BubbleSort(data));
        });

    menu.addOption("QuickSort", []() {
        std::vector<int> data = generateRandomVector();
        sortWithAlgorithm(new QuickSort(data));
        });

    while (true) {
        menu.displayMenu();
        int option;
        std::cout << "Wybierz opcję : "; //-1 wyjście
        std::cin >> option;
        if (option == -1) {
            break;
        }
        else if (std::cin.fail()) {
            std::cin.ignore(100, '\n');
        }
        menu.executeOption(option);
    }

    return 0;
}

