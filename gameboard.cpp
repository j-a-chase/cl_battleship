// Name: James A. Chase
// File: gameboard.cpp
// Date: 26 February 2024
// Description: Implementation file for gameboard.h

#include <iostream>

#include "gameboard.h"

GameBoard::GameBoard() {
    resetBoard();
}

void GameBoard::printBoard() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << "[" << board[i][j] << "] ";
        }
        std::cout << "\n";
    }
}

void GameBoard::resetBoard() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = '-';
        }
    }
}

void GameBoard::updateTile(int row, int col, bool is_hit) {
    if (is_hit) board[row][col] = 'O';
    else board[row][col] = 'X';
}
