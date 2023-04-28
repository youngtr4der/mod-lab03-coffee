// Copyright 2023 UNN
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK,
    DISPENSE
};

class Automata {
private:
    int cash;
    std::vector<std::string> menu;
    std::vector<int> prices;
    STATES state;
    int selectedDrink;
public:
    Automata();
    void on();
    void off();
    void coin(int p);
    void choice(int n);
    void check();
    void cancel();
    void cook();
    void finish();

    std::vector<std::string> getMenu() {
        return menu;
    }

    STATES getState() {
        return state;
    }

    int getBalance() {
        return cash;
    }

    void loadMenuFromFile(const std::string &filename);
};
#endif  // INCLUDE_AUTOMATA_H_