// Name: James A. Chase
// File: main.cpp
// Date: 26 February 2024

// library imports
#include <iostream>

// header imports
#include "engine.h"

int main() {
    // create game engine
    Engine* battleship = new Engine();

    // free memory
    delete battleship;

    // end program
    return 0;
}
