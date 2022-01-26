//
// Created by krzysztof on 16.06.2021.
//

#include "Game.h"

Game::Game(sf::Vector2<unsigned int> windowSize, Level level) {
    target.setPosition(200, 200);
    this->windowSize = windowSize;
    this->level = level;
}

void Game::checkIfTargetClicked(const sf::Mouse Mouse, const float X, const float Y) {
    if (this->target.checkIfClicked(Mouse, X, Y, windowSize)) {
        this->points += this->tmpPoints;
        this->tmpPoints = 0;
    }
    if (level == PRO && this->target2.checkIfClicked(Mouse, X, Y, windowSize)) {
        this->points += this->tmpPoints2;
        this->tmpPoints2 = 0;
    }
}

void Game::update() {
    this->target.enlarge(level + 1);
    this->tmpPoints = this->target.getRadius();
    if(level == PRO){
        this->target2.enlarge(level);
        this->tmpPoints2 = this->target2.getRadius();
    }
}

int Game::getShotDownTargetsNumber() {
    int res =  target.getNumber();
    if(level == PRO){
        res += target2.getNumber();
    }
    return res;
}

int Game::getPoints() const {
    return this->points;
}

void Game::draw(sf::RenderTarget &renderTarget, sf::RenderStates states) const {
    renderTarget.clear(sf::Color(69, 78, 92));
    renderTarget.draw(this->target);
    if(level == PRO){
        renderTarget.draw(this->target2);
    }
}