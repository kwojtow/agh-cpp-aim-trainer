//
// Created by krzysztof on 16.06.2021.
//
#include <SFML/Graphics.hpp>
#include "TextInput.h"
#include "Button.h"
#include "DatabaseService.h"

#ifndef PROJECT_RESULT_H
#define PROJECT_RESULT_H


class ResultsScreen : public  sf::Drawable{
private:
    int score;
    std::string level;
    sf::String results;
    sf::Font font;
    sf::Text resultsBox;
    sf::Text prompt;
    TextInput input{100, 200};
    Button apply{300, 600, 600, 50, "SAVE"};

    std::string getDate();

public:
    ResultsScreen(int score, std::string level);
    void writeName(sf::Event event);
    bool checkIfApplied(sf::Mouse Mouse, float X, float Y);
    void draw(sf::RenderTarget& renderTarget, sf::RenderStates states) const override;
};


#endif //PROJECT_RESULT_H
