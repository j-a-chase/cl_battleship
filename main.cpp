// Name: James A. Chase
// File: main.cpp
// Date: 26 February 2024

#include <iostream>

#include "engine.h"

int main() {
    Engine* battleship = new Engine();
    battleship->runGame();
    delete battleship;
    return 0;
}