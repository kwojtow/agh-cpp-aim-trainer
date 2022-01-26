//
// Created by krzysztof on 16.06.2021.
//

#include "Application.h"

Application::Application() {
    window.setFramerateLimit(60);
    window.setPosition(sf::Vector2<int>(100, 100));

    target.setPosition(200, 200);
}

void Application::run() {
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                        case sf::Keyboard::Escape:
                            window.create(sf::VideoMode(1280, 800), "Aim Trainer",
                                          sf::Style::Titlebar | sf::Style::Close);
                            break;
                        default:
                            break;
                    }
                    break;
                case sf::Event::MouseButtonPressed:
                    if (state == 0) {
                        level = levelMenu.changeLevel(sf::Mouse(), (float) sf::Mouse::getPosition(window).x,
                                                      (float) sf::Mouse::getPosition(window).y);
                        if (level.change) {
                            state = 1;
                            game = new Game(window.getSize(), level.level);
                        }
                    }
                    if (state == 1) {
                        game->checkIfTargetClicked(sf::Mouse(), (float) sf::Mouse::getPosition(window).x,
                                                   (float) sf::Mouse::getPosition(window).y);
                    }
                    if (state == 2) {
                        if (result->checkIfApplied(sf::Mouse(), (float) sf::Mouse::getPosition(window).x,
                                                   (float) sf::Mouse::getPosition(window).y)) {
                            rank = new RankScreen();
                            state = 3;
                        }
                    }
                    if (state == 3) {
                        if (rank->checkIfClicked(sf::Mouse(), (float) sf::Mouse::getPosition(window).x,
                                                 (float) sf::Mouse::getPosition(window).y)) {
                            state = 0;
                        }
                    }
                    break;
                case sf::Event::TextEntered:
                    if (state == 2) {
                        result->writeName(event);
                    }
                    break;
                default:
                    break;
            }
        }

        if (state == 0) {
            window.draw(levelMenu);
        }
        if (state == 1) {
            game->update();
            window.draw(*game);
            if (game->getShotDownTargetsNumber() >= roundLength) {
                state = 2;
                result = new ResultsScreen(game->getPoints(), levelNames[level.level]);
            }
        }
        if (state == 2) {
            window.draw(*result);
        }
        if (state == 3) {
            window.draw(*rank);
        }

        window.display();
    }
}