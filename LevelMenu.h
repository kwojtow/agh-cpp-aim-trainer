//
// Created by krzysztof on 16.06.2021.
//
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "common.h"

#ifndef PROJECT_LEVELMENU_H
#define PROJECT_LEVELMENU_H


class LevelMenu : public sf::Drawable
{
private:
    Button noob{200, 200, 800, 50, "NOOB"};
    Button medium{200, 300, 800, 50, "MEDIUM"};
    Button pro{200, 400, 800, 50, "PRO"};
    Level level = MEDIUM;
    sf::Text header;
    sf::Font font;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    LevelMenu();
    LevelChange changeLevel(const sf::Mouse Mouse, const float X, const float Y);
};


#endif //PROJECT_LEVELMENU_H
