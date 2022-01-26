//
// Created by krzysztof on 16.06.2021.
//

#include "TextInput.h"

    TextInput::TextInput(float left, float top) {

        font.loadFromFile("tnr.ttf");

        this->text.setFillColor(sf::Color::Black);

        this->text.setFont(font);
        this->text.setCharacterSize(50);
        this->text.setPosition(310, 300);


        this->rect.setFillColor(sf::Color::White);
        sf::Vector2<float> tmp = {600, 80};
        this->rect.setSize(tmp);
        this->rect.setPosition(300, 300);
    }

    void TextInput::changeText(sf::Event event){
        if (event.text.unicode == '\b') {
            if (playerInput.getSize() >= 1) {
                playerInput.erase(playerInput.getSize() - 1);
            }
        } else if (playerInput.getSize() < 10) {
            playerInput += event.text.unicode;
        }
        this->text.setString(playerInput);
    }

sf::String TextInput::getText() {
    return this->playerInput;
}

void TextInput::draw(sf::RenderTarget &renderTarget, sf::RenderStates states) const {
    renderTarget.draw(this->rect);
    renderTarget.draw(this->text);
}
