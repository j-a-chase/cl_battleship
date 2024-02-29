// Name: James A. Chase
// File: board.h
// Date: 26 February 2024
// Description: Header file for pure virtual Board class

#ifndef BOARD_H
#define BOARD_H

class Board {
    protected:
        char board[10][10];

    public:
        virtual void printBoard() = 0;
        virtual void resetBoard() = 0;

        char (*getBoard())[10] { return board; }
};

#endif
