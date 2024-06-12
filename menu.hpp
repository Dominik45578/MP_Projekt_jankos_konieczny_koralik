#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include "sortingalg.hpp"

class Menu {
public:
    Menu();
    void addOption(const std::string& name, SortingAlg* algorithm);
    void displayMenu() const;
    SortingAlg* executeOption(int option);
    void menu();
    std::vector<int>loadArrayFromFile(const std::string& filename);

private:
    friend class SortingAlg;
    struct Option {
        std::string name;
        SortingAlg* algorithm;
    };
    std::unordered_map<int, Option> optionMap;
    int optionCount = 1;

    void loadOptionsFromFile();
    void saveOptionsToFile();
};

/*#ifndef MENU_HPP
#define MENU_HPP

#include <unordered_map>
#include <vector>
#include <functional>
#include <iostream>
#include <fstream>
#include "sortingalg.hpp"

class Menu {
public:
    Menu();
    void addOption(const std::string& name, std::function<void()> func);
    void displayMenu() const;
    void executeOption(int option);

private:
    struct Option {
        std::string name;
        std::function<void()> func;
    };
    std::unordered_map<int, Option> optionMap;
    int optionCount = 1;

    void loadOptionsFromFile();
    void saveOptionsToFile();
};

#endif // MENU_HPP


#include <iostream>
#include <functional>
#include <fstream>
#include <map>
#include <string>
#include <unordered_map>
#include <memory>
#include <sstream>

class Menu {
    struct Option {
        std::string optionName;
        std::function<void(int)> optionFunc;
    };

    std::map<int, Option> optionMap; // chcemy mieæ zawsze posortowane wiêc najlpiej u¿yæ mapy bo struktura drzewa gwarantuje porz¹dek rosn¹cy 
    int keyCount = 0;               // w celu iteracji mo¿na u¿yæ typu std::map<int , Option> :: iterator& it
    Menu() = default;
    ~Menu() = default;
    Menu(const Menu&) = delete;            //menu oparte na singletonie - brak konstuktora przenosz¹cego i wy³¹czenie = nie powinno wykrzaczyæ clasy
    Menu& operator=(const Menu&) = delete;

    static std::unordered_map<std::string, std::function<void(int)>> functionRegistry;   // rejestr funkcji trzymam w nim wczytywane funkcje 
    void fileWrite();
public:
    static Menu& getInstance() {  // zwracanie ju¿ istniej¹cego obiektu
        static Menu instance;
        return instance;
    }

    void fileRead();
    void add(const std::string& addName, const std::string& addFuncName);
    void del(int it);
    void getOption(int it);
    void menuView();

    void sampleFunction1(int opt);
    void sampleFunction2(int opt);

    void registerFunctions();

    friend std::ostream& operator<<(std::ostream& os, const Menu& m);
};

#define REGISTER_FUNCTION(func) \
    Menu::functionRegistry[#func] = std::bind(&Menu::func, &Menu::getInstance(), std::placeholders::_1); // typ lambda i makro
    // tzw lambda bind - wi¹¿emy funkcjê dynamicznie zamiast statycznie  
#endif // MENU_H
*/