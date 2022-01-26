//
// Created by krzysztof on 16.06.2021.
//
#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include "Row.h"
#include "Button.h"

#ifndef PROJECT_TABLE_H
#define PROJECT_TABLE_H


class Table : public sf::Drawable{
private:
    int rowHeight = 50;
    Button* headerButtons[4]{};
    Row* rows[10]{};
    int rowsNumber;
    std::string headerValues[4] = {"NICKNAME", "SCORE", "DATE", "LEVEL"};
public:
    Table(int left, int top, int width, const std::list<std::string>& values);
    void draw(sf::RenderTarget& renderTarget, sf::RenderStates states) const override;
};


#endif //PROJECT_TABLE_H
