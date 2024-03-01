// Name: James A. Chase
// File: board.h
// Date: 26 February 2024
// Description: Header file for pure virtual Board class

#ifndef BOARD_H
#define BOARD_H

// Board class
class Board {
    protected:
        // 2-D char array to represent the game board
        char board[10][10];

    public:
        // virtual functions to print board and reset the board for a new game
        virtual void printBoard();
        virtual void resetBoard();

        // getter for protected board attribute
        char (*getBoard())[10] { return board; }
};

#endif
