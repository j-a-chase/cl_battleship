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

// resetBoard implementation
void ShipBoard::resetBoard() {
    // call parent function
    Board::resetBoard();

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
