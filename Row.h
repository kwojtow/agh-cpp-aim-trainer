//
// Created by krzysztof on 16.06.2021.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

#ifndef PROJECT_ROW_H
#define PROJECT_ROW_H


class Row : public sf::Drawable{
private:
    int width;
    int height;
    sf::RectangleShape cels[5];
    sf::Text celsVal[5];
    sf::Font font;
public:
    Row(int nr, std::list<std::string> values, int width, int height, int left, int top);
    void draw(sf::RenderTarget& renderTarget, sf::RenderStates states) const override;

};


#endif //PROJECT_ROW_H
