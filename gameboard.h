// Name: James A. Chase
// File: gameboard.h
// Date: 26 February 2024
// Description: Header file for GameBoard subclass

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

// header imports
#include "board.h"

// GameBoard class to represent where player shots will go, inherits from Board parent class
class GameBoard : public Board {
    public:
        // constructor
        GameBoard();

        // override parent virtual functions
        void printBoard() override;
        void resetBoard() override;
        
        // function to update a tile on the board when a shot is fired
        void updateTile(int row, int col, bool is_hit);
};

#endif
