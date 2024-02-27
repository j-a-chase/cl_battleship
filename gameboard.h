// Name: James A. Chase
// File: gameboard.h
// Date: 26 February 2024
// Description: Header file for GameBoard subclass

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "board.h"

class GameBoard : public Board {
    public:
        GameBoard();

        void printBoard() override;
        void resetBoard() override;
        
        void updateTile(int row, int col, bool is_hit);
};

#endif
