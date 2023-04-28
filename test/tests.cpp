// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(AutomataTest, OnOffState) {
    Automata automata;

    automata.on();
    EXPECT_EQ(automata.getState(), WAIT);

    automata.off();
    EXPECT_EQ(automata.getState(), OFF);
}

TEST(AutomataTest, CheckThirdIngredient) { // проверка 3 напитка в текущем menu.txt
    Automata automata;

    std::vector<std::string> menu = automata.getMenu();
    ASSERT_GE(menu.size(), 3); // Проверяем, что в меню есть хотя бы три напитка
    // Проверяем название и стоимость третьего напитка
    EXPECT_EQ(menu[2], "Cappuccino");
}

TEST(AutomataTest, Coin) {
    Automata automata;
    automata.on();
    automata.coin(100);
    EXPECT_EQ(automata.getState(), ACCEPT);
    EXPECT_EQ(automata.getBalance(), 100);
}

TEST(AutomataTest, ChoiceAndCheck) {
    Automata automata;

    automata.on();
    automata.coin(200);

    automata.choice(1); // напиток из примера menu.txt: Americano за 120
    EXPECT_EQ(automata.getState(), COOK);

    automata.finish();

    // Тестирование с некорректным номером напитка
    automata.coin(200);
    automata.choice(100); // Несуществующий номер напитка
    EXPECT_EQ(automata.getState(), ACCEPT);

    // Тестирование с недостаточным количеством денег
    automata.coin(50);
    automata.choice(1); // напиток из примера menu.txt: Americano за 120
    EXPECT_EQ(automata.getState(), ACCEPT);
}

TEST(AutomataTest, Cancel) {
    Automata automata;

    automata.on();
    automata.coin(100);
    automata.cancel();
    EXPECT_EQ(automata.getState(), WAIT);
}
