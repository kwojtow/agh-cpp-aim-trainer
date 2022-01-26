//
// Created by krzysztof on 16.06.2021.
//

#include "LevelMenu.h"
#include "common.h"

    LevelMenu::LevelMenu() {
        font.loadFromFile("tnr.ttf");
        this->header.setString("Choose level");
        this->header.setCharacterSize(100);
        this->header.setFont(font);
        this->header.setFillColor(sf::Color(35, 41, 51));
        this->header.setOrigin(this->header.getLocalBounds().width / 2, this->header.getLocalBounds().top);
        this->header.setPosition(600, 50);
    }
    void LevelMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const{
        target.clear(sf::Color::White);
        target.draw(this->header);
        target.draw(this->noob);
        target.draw(this->medium);
        target.draw(this->pro);
    }

    LevelChange LevelMenu::changeLevel(const sf::Mouse Mouse, const float X, const float Y)
    {
        LevelChange res;
        if(this->noob.isClicked(Mouse, X,Y)){
            this->level = NOOB;
            res.change = true;
        }
        if(this->medium.isClicked(Mouse, X, Y)){
            this->level = MEDIUM;
            res.change = true;
        }
        if (this->pro.isClicked(Mouse, X, Y)){
            this->level = PRO;
            res.change = true;
        }
        res.level = this->level;
        return res;
    }