#include "menu.hpp"
#include "MergeSort.hpp"
#include "HeapSort.hpp"
#include "BubbleSort.hpp"
#include "QuickSort.hpp"
#include <random>
#include <ctime>
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
void Menu::menu() {
    while (true) {
        std::cout << "\n\
                                  |< < <----------------------- MENU -----------------------> > >|\n\
                                  |< < <--------------- ALGORYTMY SORTUJACE ----------------> > >|\n\
                                  |< < <----------------------------------------------------> > >|\n";
        displayMenu();
        int option;
        std::cout << "Wybierz opcje (-1 aby wyjsc): ";
        std::cin >> option;
        if (option == -1) {
            break;
        }
        else if (option < 0 || std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            system("cls");
            continue;
        }
        system("cls");
        SortingAlg*object = executeOption(option);
        if (object == nullptr) { continue; }
        int amount;
        bool loading;
        do {
            std::cout << "Podaj miejsce wczyywania - (0 - losowo/1 - plik )  :  ";
            std::cin >> loading;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            else
                break;
        } while (true);
        if (!loading) {
            do {
                std::cout << "Podaj ilosc elementow do posortowania  :  ";
                std::cin >> amount;
                if (std::cin.fail() || amount < 0) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                }
                else
                    object->data = generateRandomVector(amount);
                    break;
            } while (true);
        }
        if (loading) {
            std::string inputfile;
            std::cout << "Podaj nazwe pliku (default : input_arrayDB.txt    - def) :  ";
            std::cin >> inputfile ;
            if(inputfile=="def"){
                object->data = loadArrayFromFile();
            }
            else {
                object->data = loadArrayFromFile(inputfile);
            }
        }
        if (object->data.size() < 1) {
            std::cout << "Brak elementow w wektorze\n";
            continue;
        }

        std::cout << "Tablica nie posortowana :  \n";
        object->print();
        std::cout << "\nTablica  posortowana :  \n";
        object->sortAndSave(object->name);

    }
}
Menu::Menu() {
    //loadOptionsFromFile();
}

void Menu::addOption(const std::string& name, SortingAlg* algorithm) {
    optionMap[optionCount] = { name, algorithm };
    optionCount++;
}

void Menu::displayMenu() const {
    std::cout << "Opcje:\n";
    for (const auto& pair : optionMap) {
        std::cout << pair.first << " - " << pair.second.name << std::endl;
    }
}

SortingAlg*Menu::executeOption(int option) {
    if (optionMap.find(option) != optionMap.end()) {
        return optionMap[option].algorithm;
       
    }
    else {
        std::cout << "Nieprawid≥owa opcja.\n";
        return nullptr;
    }
}

void Menu::loadOptionsFromFile() {
    std::ifstream inputfile("menudatabase.txt");
    if (!inputfile.is_open()) {
        std::cerr << "Wykryto blad podczas wczytywania opcji menu z pliku\n";
        return;
    }

    int key;
    std::string name;
    while (inputfile >> key) {
        inputfile.ignore();
        std::getline(inputfile, name);
        optionMap[key] = { name, nullptr };  // Inicjalnie ustawiamy wskaünik na nullptr
        optionCount = std::max(optionCount, key + 1);
    }

    inputfile.close();
}

void Menu::saveOptionsToFile() {
    std::ofstream outputfile("menudatabase.txt", std::ios::trunc|std::ios::app);
    if (!outputfile.is_open()) {
        std::cerr << "Problem z zapisem do pliku.\n";
        return;
    }

    for (const auto& pair : optionMap) {
        outputfile << pair.first << " " << pair.second.name << std::endl;
    }

    outputfile.close();
}
std::vector<int> Menu::loadArrayFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<int> array;
    int value;

    if (!file.is_open()) {
        std::cerr << "Nie moøna otworzyÊ pliku: " << filename << std::endl;
        return array;
    }

    while (file >> value) {
        if (file.fail()) {
            file.ignore(100, '\n');
            file.clear();
        }
        array.push_back(value);
    }

    file.close();
    return array;
}