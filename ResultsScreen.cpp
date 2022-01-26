//
// Created by krzysztof on 16.06.2021.
//

#include "ResultsScreen.h"

std::string ResultsScreen::getDate() {
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M", timeinfo);
    std::string str(buffer);

    return str;
}

ResultsScreen::ResultsScreen(int score, std::string level) {
    this->score = score;
    this->level = level;
    this->font.loadFromFile("tnr.ttf");
    this->results = "Your score is: " + std::to_string(score);
    this->resultsBox.setFont(this->font);
    this->resultsBox.setFillColor(sf::Color::Black);
    this->resultsBox.setString(this->results);
    this->resultsBox.setCharacterSize(100);
    this->resultsBox.setOrigin(this->resultsBox.getLocalBounds().width / 2, this->resultsBox.getLocalBounds().top);
    this->resultsBox.setPosition(600, 100);

    this->prompt.setFont(font);
    this->prompt.setString("Enter your name:");
    this->prompt.setFillColor(sf::Color::Black);
    this->prompt.setCharacterSize(50);
    this->prompt.setOrigin(this->prompt.getLocalBounds().width / 2, this->prompt.getLocalBounds().top);
    this->prompt.setPosition(600, 240);
}

void ResultsScreen::writeName(sf::Event event) {
    this->input.changeText(event);
}

bool ResultsScreen::checkIfApplied(const sf::Mouse Mouse, const float X, const float Y) {
    bool res= this->apply.isClicked(Mouse, X, Y);
    if (res) {
        DatabaseService databaseService{};
        databaseService.insertData(this->input.getText(), this->score, getDate(), this->level);
    }
    return res;
}

void ResultsScreen::draw(sf::RenderTarget &renderTarget, sf::RenderStates states) const {
    renderTarget.clear(sf::Color(69, 78, 92));
    renderTarget.draw(this->resultsBox);
    renderTarget.draw(this->prompt);
    renderTarget.draw(this->input);
    renderTarget.draw(this->apply);
}