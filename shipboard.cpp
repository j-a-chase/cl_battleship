// Name: James A. Chase
// File: shipboard.cpp
// Date: 26 February 2024
// Description: Implementation file for ShipBoard class

#include <iostream>

#include "shipboard.h"

ShipBoard::ShipBoard() {
    resetBoard();
}

void ShipBoard::printBoard() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << "[" << board[i][j] << "] ";
        }
        std::cout << "\n";
    }
}

void ShipBoard::resetBoard() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = '-';
        }
    }
    placeShips();
}

void ShipBoard::placeShips() {
    // 5-length ship
    for (int col = 3; col < 8; col++) {
        board[1][col] = 'S';
    }

    // 4-length ship
    for (int row = 2; row < 6; row++) {
        board[row][8] = 'S';
    }

    // 3-length ship
    for (int col = 0; col < 3; col++) {
        board[5][col] = 'S';
    }

    // 2-length ship
    for (int row = 8; row < 10; row++) {
        board[row][7] = 'S';
    }
}
