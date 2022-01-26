//
// Created by krzysztof on 16.06.2021.
//
#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include "Table.h"
#include "Button.h"
#include "DatabaseService.h"

#ifndef PROJECT_RANKSCREEN_H
#define PROJECT_RANKSCREEN_H


class RankScreen : public sf::Drawable{
private:
    Table* table;
    Button* button;
    std::list<std::string> values;
    DatabaseService databaseService{};
    std::list<std::string> res;


public:
    RankScreen();
    bool checkIfClicked(const sf::Mouse Mouse, const float X, const float Y);
    void draw(sf::RenderTarget& renderTarget, sf::RenderStates states) const override;

};


#endif //PROJECT_RANKSCREEN_H
