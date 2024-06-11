#include "menu.hpp"
#include "MergeSort.hpp"
#include "HeapSort.hpp"
#include "BubbleSort.hpp"
#include "QuickSort.hpp"
#include "sortingalg.hpp"
#include <random>

Menu::Menu() {
    loadOptionsFromFile();
}

void Menu::addOption(const std::string& name, std::function<void()> func) {
    optionMap[optionCount] = { name, func };
    optionCount++;
    saveOptionsToFile();
}

void Menu::displayMenu() const {
    std::cout << "Opcje :\n";
    for (const auto& pair : optionMap) {
        std::cout << pair.first << " - " << pair.second.name << std::endl;
    }
}

void Menu::executeOption(int option) {
    if (optionMap.find(option) != optionMap.end()) {
        optionMap[option].func();
    }
    else {
        std::cout << "Wykryto blad podczas ladowania opcji \n";
    }
}

void Menu::loadOptionsFromFile() {
    std::ifstream inputfile("menudatabase.txt");
    if (!inputfile.is_open()) {
        std::cerr << "Wykryto blad podczas wczytywania opcji menu z pliku \n";
        return;
    }

    int key;
    std::string name;
    while (inputfile >> key) {
        inputfile.ignore();
        std::getline(inputfile, name);
        optionMap[key] = { name, []() { std::cout << "Nie zaladowano funkcji \n"; } };
        optionCount = std::max(optionCount, key + 1);
    }

    inputfile.close();
}

void Menu::saveOptionsToFile() {
    std::ofstream outputfile("menudatabase.txt");
    if (!outputfile.is_open()) {
        std::cerr << "Problem z zapisem do pliku .\n";
        return;
    }

    for (const auto& pair : optionMap) {
         outputfile<< pair.first << " - " << pair.second.name << std::endl;
    }

    outputfile.close();
}
