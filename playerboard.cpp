// Name: James A. Chase
// File: playerboard.cpp
// Date: 26 February 2024
// Description: Implementation file for PlayerBoard class

// library imports
#include <iostream>
#include <string>

// header imports
#include "playerboard.h"
#include "validation.h"

// constructor implementation
PlayerBoard::PlayerBoard() {
    // calls resetBoard method to initialize board attribute
    resetBoard();
}

// setShip implementation
void PlayerBoard::setShip(int size) {
    // values to hold the orientation, row, and column inputs from user
    int orient, x, y;

    // holds upper bound of ship placement based on size
    int upper = 10 - size;

    // determines if placement of ship is valid
    bool valid_placement = false;

    // determine if user input is valid
    bool valid_input = false;

    // get orientation input
    std::cout << "How do you want to orient the " << size << "-ship?" << std::endl;
    std::cout << "\t[0] Horizontally\n";
    std::cout << "\t[1] Vertically\n";
    orient = validateInput("> ");

    // if horizontal
    if (orient == 0) {
        // while not valid placement
        while (!valid_placement) {
            // get row and column
            x = validateInput("Which row? [0-9]: ");
            y = validateInput("Which column to start in? [0-" + std::to_string(upper) + "]: ");

            // ensure row is in bounds
            if (x < 0) x = 0;
            else if (x > 9) x = 9;

            // ensure column is in bounds
            if (y < 0) y = 0;
            else if (y > upper) y = upper;

            // search following tiles for other ships based on user input
            valid_placement = true;
            for (int col = y; col < y + size; col++) {
                if (board[x][col] == 'S') valid_placement = false;
            }

            // if still not valid, print warning and loop through again
            if (!valid_placement) std::cout << "You can't place a ship on top of another one!!\n\n";
        }

        // 'place' ship
        for (int col = y; col < y + size; col++) {
            board[x][col] = 'S';
        }
    // else vertical
    } else {
        // while not valid placement
        while (!valid_placement) {
            // get user input
            y = validateInput("Which column? [0-9]: ");
            x = validateInput("Which row to start in? [0-" + std::to_string(upper) + "]: ");

            // ensure column is in bounds
            if (y < 0) y = 0;
            else if (y > 9) y = 9;

            // ensure row is in bounds
            if (x < 0) x = 0;
            else if (x > upper) x = upper;

            // search following tiles for ships based on user input
            valid_placement = true;
            for (int row = x; row < x + size; row++) {
                if (board[row][y] == 'S') valid_placement = false;
            }

            // if still not valid, print warning and loop through again
            if (!valid_placement) std::cout << "You can't place a ship on top of another one!!\n\n";
        }

        // 'place' ship
        for (int row = x; row < x + size; row++) {
            board[row][y] = 'S';
        }
    }
}

// setShips implementation
void PlayerBoard::setShips() {
    // loop through valid ship sizes (5, 4, 3, 2) and place them
    for (int i = 5; i > 1; i--) {
        // place ship
        setShip(i);

        // show user updated board before next placement
        printBoard();
    }
}

// updateTile implementation
void PlayerBoard::updateTile(int row, int col, bool is_hit) {
    // update tiles based on if the cpu hit or not
    if (is_hit) board[row][col] = 'X';
    else board[row][col] = 'm';
}
