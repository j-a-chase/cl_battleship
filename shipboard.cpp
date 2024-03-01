// Name: James A. Chase
// File: shipboard.cpp
// Date: 26 February 2024
// Description: Implementation file for ShipBoard class

// library imports
#include <iostream>

// header imports
#include "shipboard.h"

// constructor implementation
ShipBoard::ShipBoard() {
    // simply calls the resetBoard method, will be used to start a new game later
    resetBoard();
}

// printBoard implementation
void ShipBoard::printBoard() {
    // loop through each individual tile value and print it with brackets around it
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << "[" << board[i][j] << "] ";
        }

        // make a newline every 10 values (10x10 grid)
        std::cout << "\n";
    }
}

// resetBoard implementation
void ShipBoard::resetBoard() {
    // initialize every value in the board to '-'
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = '-';
        }
    }

    // hide cpu ships
    placeShips();
}

// placeShips implementation
void ShipBoard::placeShips() {
    /*

    Designed to support random placement of ships at a future point.
    Currently places ships in static positions on cpu board.

    */
    
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
