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

// updateTile implementation
void GameBoard::updateTile(int row, int col, bool is_hit) {
    // update board to reflect if the player hit or not
    if (is_hit) board[row][col] = 'O';
    else board[row][col] = 'X';
}
