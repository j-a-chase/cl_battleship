// Name: James A. Chase
// File: playerboard.cpp
// Date: 26 February 2024
// Description: Implementation file for PlayerBoard class

#include <iostream>

#include "playerboard.h"

PlayerBoard::PlayerBoard() {
    resetBoard();
}

void PlayerBoard::printBoard() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << "[" << board[i][j] << "] ";
        }
        std::cout << "\n";
    }
}

void PlayerBoard::resetBoard() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = '-';
        }
    }
}

void PlayerBoard::setShip(int size) {
    int orient, x, y;
    int upper = 10 - size;
    bool valid_placement = false;

    std::cout << "How do you want to orient the " << size << "-ship?" << std::endl;
    std::cout << "\t[0] Horizontally\n";
    std::cout << "\t[1] Vertically\n> ";
    std::cin >> orient;

    if (orient == 0) {
        while (!valid_placement) {
            std::cout << "Which row? [0-9]: ";
            std::cin >> x;

            std::cout << "Which column to start in? [0-" << upper << "]: ";
            std::cin >> y;

            if (x < 0) x = 0;
            else if (x > 9) x = 9;

            if (y < 0) y = 0;
            else if (y > upper) y = upper;

            valid_placement = true;
            for (int col = y; col < y + size; col++) {
                if (board[x][col] == 'S') valid_placement = false;
            }

            if (!valid_placement) std::cout << "You can't place a ship on top of another one!!\n\n";
        }

        for (int col = y; col < y + size; col++) {
            board[x][col] = 'S';
        }
    } else {
        while (!valid_placement) {
            std::cout << "Which column? [0-9]: ";
            std::cin >> y;

            std::cout << "Which row to start in? [0-" << upper << "]: ";
            std::cin >> x;

            if (y < 0) y = 0;
            else if (y > 9) y = 9;

            if (x < 0) x = 0;
            else if (x > upper) x = upper;

            valid_placement = true;
            for (int row = x; row < x + size; row++) {
                if (board[row][y] == 'S') valid_placement = false;
            }

            if (!valid_placement) std::cout << "You can't place a ship on top of another one!!\n\n";
        }

        for (int row = x; row < x + size; row++) {
            board[row][y] = 'S';
        }
    }
}

void PlayerBoard::setShips() {
    for (int i = 5; i > 1; i--) {
        setShip(i);
        printBoard();
    }
}