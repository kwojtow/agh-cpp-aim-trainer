//
// Created by krzysztof on 16.06.2021.
//

#include "Button.h"


Button::Button(int left, int top, int width, int height, const sf::String &value) {
    font.loadFromFile("tnr.ttf");
    this->text.setCharacterSize(2 * height / 3);
    this->text.setFillColor(sf::Color(230, 232, 235));
    this->text.setFont(font);
    this->text.setString(value);
    this->text.setOrigin(this->text.getLocalBounds().width / 2, this->text.getLocalBounds().top);
    this->text.setPosition(left + width / 2 + 20, top + 10);

    this->box.left = left;
    this->box.top = top;
    this->box.width = width + 40;
    this->box.height = height;
    this->rect.setPosition((float) left, (float) top);
    this->rect.setSize(sf::Vector2f((float) width + 40, (float) height));
    this->rect.setFillColor(sf::Color(35, 41, 51));
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(this->rect);
    target.draw(this->text);
}

bool Button::isClicked(const sf::Mouse Mouse, const float X, const float Y) const {
    if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) { return false; }
    return box.contains(X, Y);
}

void Button::changeState() {
    this->state = !this->state;
    if (this->state) {
        this->rect.setFillColor(sf::Color::Green);
    } else {
        this->rect.setFillColor(sf::Color::Red);
    }
}
