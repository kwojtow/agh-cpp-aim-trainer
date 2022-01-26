//
// Created by krzysztof on 16.06.2021.
//
#include <SFML/Graphics.hpp>

#ifndef PROJECT_TEXTINPUT_H
#define PROJECT_TEXTINPUT_H


class TextInput : public sf::Drawable{
    sf::Text text;
    sf::String playerInput;
    sf::Font font;
    sf::RectangleShape rect;

public:
    TextInput(float left, float top);

    void changeText(sf::Event event);

    sf::String getText();

    void draw(sf::RenderTarget& renderTarget, sf::RenderStates states) const override;

};


#endif //PROJECT_TEXTINPUT_H
