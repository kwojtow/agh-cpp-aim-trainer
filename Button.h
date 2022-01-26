//
// Created by krzysztof on 16.06.2021.
//
#include <SFML/Graphics.hpp>

#ifndef PROJECT_BUTTON_H
#define PROJECT_BUTTON_H

class Button : public sf::Drawable {
private:
    sf::RectangleShape rect;
    sf::IntRect box;
    sf::Text text;
    sf::Font font;
    bool state = false;

public:
    Button(int left, int top, int width, int height, const sf::String &value);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    bool isClicked(const sf::Mouse Mouse, const float X, const float Y) const;

    void changeState();

};


#endif //PROJECT_BUTTON_H
