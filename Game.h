//
// Created by krzysztof on 16.06.2021.
//

#include <SFML/Graphics.hpp>
#include "Target.h"
#include "common.h"

#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H


class Game : public sf::Drawable{
private:
    Target target{0.f, false};
    Target target2{0.f, false};
    int tmpPoints = 0;
    int tmpPoints2 = 0;
    int points{};
    sf::Vector2<unsigned int > windowSize;
    Level level;

public:

    explicit Game(sf::Vector2<unsigned int> windowSize, Level level);
    void checkIfTargetClicked(const sf::Mouse Mouse, const float X, const float Y);
    void update();
    int getShotDownTargetsNumber();
    int getPoints() const;
    void draw(sf::RenderTarget& renderTarget, sf::RenderStates states) const override;
};


#endif //PROJECT_GAME_H
