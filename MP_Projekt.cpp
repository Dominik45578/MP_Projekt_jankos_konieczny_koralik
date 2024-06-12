#include "sortingalg.hpp"
#include "MergeSort.hpp"
#include "HeapSort.hpp"
#include "BubbleSort.hpp"
#include "QuickSort.hpp"
#include "menu.hpp"
#include <vector>
#include <random>
#include <iostream>
int main() {
    Menu menu;

    // Dodawanie opcji sortowania do menu
    menu.addOption("Merge Sort", new MergeSort("Merge_Sort"));
    menu.addOption("Heap Sort", new HeapSort("Heap_Sort"));
    menu.addOption("Bubble Sort", new BubbleSort("Bubble_Sort"));
    menu.addOption("Quick Sort", new QuickSort("Quick_Sort"));
    menu.menu();

    return 0;
}
