// Name: James A. Chase
// File: gameboard.cpp
// Date: 26 February 2024
// Description: Implementation file for gameboard.h

// library imports
#include <iostream>

// header imports
#include "gameboard.h"

// constructor implementation
GameBoard::GameBoard() {
    // calls resetBoard to initialize the board attribute
    resetBoard();
}

// printBoard implementation
void GameBoard::printBoard() {
    // prints each value in the board attribute surrounded by brackets - []
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << "[" << board[i][j] << "] ";
        }

        // start newline every 10 values
        std::cout << "\n";
    }
}

// resetBoard implementation
void GameBoard::resetBoard() {
    // initialize every value to '-'
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = '-';
        }
    }
}

// updateTile implementation
void GameBoard::updateTile(int row, int col, bool is_hit) {
    // update board to reflect if the player hit or not
    if (is_hit) board[row][col] = 'O';
    else board[row][col] = 'X';
}
