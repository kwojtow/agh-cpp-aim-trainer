//
// Created by krzysztof on 16.06.2021.
//

#include "Row.h"


Row::Row(int nr, std::list<std::string> values, int width, int height, int left, int top) {
    this->width = width;
    this->height = height;
    sf::Vector2<float> tmp{(float) this->width / 25, (float) height};


    this->cels[0].setSize(tmp);
    this->cels[0].setPosition((float) left, (float) top);
    this->celsVal[0].setPosition((float) left, (float) top);
    this->celsVal[0].setString(std::to_string(nr + 1));
    for (int i = 1; i < 5; i++) {
        sf::Vector2<float> tmp2{static_cast<float>(6 * (float) this->width / 25), (float) height};
        this->cels[i].setSize(tmp2);
        this->cels[i].setPosition((float) left + (float) width / 25 + (float) (i - 1) * (6 * (float) width / 25),
                                  (float) top);
        this->celsVal[i].setPosition((float) left + (float) width / 25 + (float) (i - 1) * (6 * (float) width / 25),
                                     (float) top);

        auto l_front = values.begin();
        std::advance(l_front, 4 * nr + (i - 1));
        std::string tmp = *l_front;
        this->celsVal[i].setString("\t" + tmp);
    }
    for (auto &i : this->celsVal) {
        i.setCharacterSize(2 * height / 3);
        font.loadFromFile("tnr.ttf");
        i.setFillColor(sf::Color::Black);
        i.setFont(font);
    }
}

void Row::draw(sf::RenderTarget &renderTarget, sf::RenderStates states) const {
    for (int i = 0; i < 5; i++) {
        renderTarget.draw(this->cels[i]);
        renderTarget.draw(this->celsVal[i]);
    }
}