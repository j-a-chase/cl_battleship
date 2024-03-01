// Name: James A. Chase
// File: board.cpp
// Date: 29 February 2024
// Description: Implementation file for Board class

// library imports
#include <iostream>

// header imports
#include "board.h"

void Board::printBoard() {
    // loop through each individual tile value and print it with brackets around it
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << "[" << board[i][j] << "] ";
        }

        // make a newline every 10 values (10x10 grid)
        std::cout << "\n";
    }
}

void Board::resetBoard() {
    // initialize every value to '-'
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = '-';
        }
    }
}
