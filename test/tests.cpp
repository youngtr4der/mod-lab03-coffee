// Copyright 2023 UNN

#include <gtest/gtest.h>
#include "Automata.h"

TEST(AutomataTest, OnOffState) {
    Automata automata;

    automata.on();
    EXPECT_EQ(automata.getState(), WAIT);

    automata.off();
    EXPECT_EQ(automata.getState(), OFF);
}

// проверка 3 напитка в текущем menu.txt
TEST(AutomataTest, CheckThirdIngredient) {
    Automata automata;
    std::vector<std::string> menu = automata.getMenu();
    EXPECT_EQ(menu[2], "Cappuccino");
}

TEST(AutomataTest, Coin) {
    Automata automata;
    automata.on();
    automata.coin(100);
    EXPECT_EQ(automata.getState(), ACCEPT);
    EXPECT_EQ(automata.getBalance(), 100);
}
