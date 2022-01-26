//
// Created by krzysztof on 16.06.2021.
//

#include "RankScreen.h"

RankScreen::RankScreen(){
    this->button = new Button(500, 700, 200, 50, "NEW GAME");
    this->res.clear();
    this->res = databaseService.getData("SCORE");
    this->table = new Table(20, 100, 1200, res);
}
bool RankScreen::checkIfClicked(const sf::Mouse Mouse, const float X, const float Y){
    return this->button->isClicked(Mouse, X, Y);
}

void RankScreen::draw(sf::RenderTarget& renderTarget, sf::RenderStates states) const{
    renderTarget.clear(sf::Color::White);
    renderTarget.draw(*(this->table));
    renderTarget.draw(*(this->button));
}