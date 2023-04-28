// Copyright 2023 UNN
#include "Automata.h"

Automata::Automata()
{
    cash = 0;
    state = OFF;
    loadMenuFromFile("menu.txt");
}

void Automata::on()
{
    if (state == OFF) {
        state = WAIT;
    }
}

void Automata::off()
{
    if (state == WAIT) {
        state = OFF;
    }
}

void Automata::coin(int p)
{
    if (state == WAIT) {
        cash += p;
        state = ACCEPT;
        std::cout << "Cash: " << cash << std::endl;
    } else {
        std::cout << "Invalid" << std::endl;
    }
}

void Automata::check() {
    if (state == CHECK) {
        if (selectedDrink >= 0 && selectedDrink < static_cast<int>(prices.size()) && cash >= prices[selectedDrink]) {
            state = COOK;
            cook();
        } else {
            std::cout << "Insufficient funds or invalid drink number" << std::endl;
            state = ACCEPT;
        }
    }
}

void Automata::choice(int n)
{
    if (state == ACCEPT) {
        selectedDrink = n;
        state = CHECK;
        check();
    }    
}

void Automata::cancel() {
    if (state != COOK) {
        state = WAIT;
    }
}

void Automata::cook() {
    if (state == COOK) {
        std::cout << "Preparing drink..." << std::endl;
        finish();
    }
}

void Automata::finish() {
    if (state == COOK) {
        std::cout << "Drink is ready" << std::endl;
        state = DISPENSE;
        cash = 0;
        state = WAIT;
    }
}

void Automata::loadMenuFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string drinkName;
        int drinkPrice;

        while (file >> drinkName >> drinkPrice) {
            menu.push_back(drinkName);
            prices.push_back(drinkPrice);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}
