//
// Created by krzysztof on 16.06.2021.
//
#include <SFML/Graphics.hpp>
#include <list>
#include "Target.h"
#include <iostream>
#include "Button.h"
#include "LevelMenu.h"
#include "Game.h"
#include "TextInput.h"
#include "ResultsScreen.h"
#include "Row.h"
#include "Table.h"
#include "RankScreen.h"
#include "common.h"

#ifndef PROJECT_APPLICATION_H
#define PROJECT_APPLICATION_H


class Application {
private:

    std::string levelNames[3] = {"NOOB", "MEDIUM", "PRO"};
    Target target{0.f, false};

    int roundLength = 10;
    int state = 0;

    LevelMenu levelMenu{};
    Game *game{};
    ResultsScreen *result{};
    RankScreen *rank{};

    LevelChange level{};
    sf::RenderWindow window{sf::VideoMode(1280, 800), "Aim Trainer", sf::Style::Titlebar | sf::Style::Close};

public:
    Application();
    void run();
};


#endif //PROJECT_APPLICATION_H
