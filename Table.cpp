//
// Created by krzysztof on 16.06.2021.
//

#include "Table.h"

Table::Table(int left, int top, int width, const std::list<std::string> &values) {
    for (int i = 0; i < 4; i++) {
        headerButtons[i] = new Button(left + int(width / 25) + i * (6 * width / 25), top - rowHeight, 6 * width / 25,
                                      rowHeight, headerValues[i]);
    }


    this->rowsNumber = ((int) (values.size() / 4));

    for (int i = 0; i < rowsNumber && i < 10; i++) {
        this->rows[i] = new Row(i, values, width, this->rowHeight, left, top + this->rowHeight * i);
    }

}

void Table::draw(sf::RenderTarget &renderTarget, sf::RenderStates states) const {
    for (
        auto headerButton
            : this->headerButtons) {
        renderTarget.
                draw(*headerButton);
    }
    for (
            int i = 0;
            i < rowsNumber && i <
                              10; i++) {
        renderTarget.draw(*(this->rows[i]));
    }
}