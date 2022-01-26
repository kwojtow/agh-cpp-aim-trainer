//
// Created by krzysztof on 06.06.2021.
//

#include "Target.h"


bool Target::getRole() const{
    return this->role;
}

bool Target::checkIfMouseOn(float X, float Y){
    return sqrt(pow(this->getPosition().x - X, 2) + pow(this->getPosition().y - Y, 2)) < this->getRadius();
}

void Target::reset(sf::Vector2<unsigned int> limits){
    this->number++;
    setRole(rand() % 2 == 0);
    this->setRadius(0);
    this->setPosition(static_cast <float>(rand() % limits.x), static_cast <float>(rand() % limits.y));
}
void Target::setRole(bool role){
    this->role = role;

    if(this->role){
        this->setFillColor(sf::Color(24, 135, 50));

    } else{
        this->setFillColor(sf::Color(153, 12, 5));
    }
}

Target::Target(float radius, bool role) : sf::CircleShape(radius){
    this->setRole(role);
    this->setOrigin(radius,radius);
    this->setPosition(static_cast <float>(rand() % 500), static_cast <float>(rand() % 500));
}
void Target::enlarge(int speed){
    this->setRadius(this->getRadius() + speed);
    this->setOrigin(this->getRadius(), this->getRadius());
}
int Target::getNumber(){
    return this->number;
}
void Target::resetNumber(){
    this->number = 0;
}

bool Target::checkIfClicked(const sf::Mouse Mouse, const float X, const float Y, sf::Vector2<unsigned int> limits){
    bool res = false;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (this->checkIfMouseOn(X, Y)) {
            if (!this->getRole()) {
                this->reset(limits);
                res = true;
            }
        }
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        if (this->checkIfMouseOn(X, Y)) {
            if (this->getRole()) {
                this->reset(limits);
                res = true;
            }
        }
    }
    return res;
}