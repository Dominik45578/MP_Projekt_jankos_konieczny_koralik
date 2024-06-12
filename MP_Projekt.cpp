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
    menu.addOption("Merge Sort", new MergeSort("out_Merge_Sort"));
    menu.addOption("Heap Sort", new HeapSort("out_Heap_Sort"));
    menu.addOption("Bubble Sort", new BubbleSort("out_Bubble_Sort"));
    menu.addOption("Quick Sort", new QuickSort("out_Quick_Sort"));
    menu.menu();

    return 0;
}
