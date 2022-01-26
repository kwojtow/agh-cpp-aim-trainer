//
// Created by krzysztof on 06.06.2021.
//

#include <SFML/Graphics.hpp>

#ifndef PROJECT_TARGET_H
#define PROJECT_TARGET_H
#include <iostream>
#include <math.h>


class Target : public sf::CircleShape{
private:
    bool role{}; // true equals to enemy, false equals to friend
    int number = 0;

    bool getRole() const;
    bool checkIfMouseOn(float X, float Y);
    void reset(sf::Vector2<unsigned int> limits);
    void setRole(bool role);

public:
    explicit Target(float radius, bool role);
    void enlarge(int speed);
    int getNumber();
    void resetNumber();
    bool checkIfClicked(const sf::Mouse Mouse, const float X, const float Y, sf::Vector2<unsigned int> limits);
};


#endif //PROJECT_TARGET_H
