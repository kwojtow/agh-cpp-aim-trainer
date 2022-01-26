//
// Created by krzysztof on 16.06.2021.
//
#include <iostream>

#ifndef PROJECT_COMMON_H
#define PROJECT_COMMON_H

enum Level { NOOB, MEDIUM, PRO };

typedef struct {
    bool change;
    Level level;
}LevelChange;

#endif //PROJECT_COMMON_H
