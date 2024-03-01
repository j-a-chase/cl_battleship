// Name: James A. Chase
// File: playerboard.h
// Date: 26 February 2024
// Description: Header file for PlayerBoard class

#ifndef PLAYERBOARD_H
#define PLAYERBOARD_H

// header imports
#include "board.h"

// PlayerBoard class for player to place ships and cpu to shoot against, inherits from Board parent class
class PlayerBoard : public Board {
    private:
        // function to place a ship of a given size
        void setShip(int size);

    public:
        // constructor
        PlayerBoard();
    
        // override parent virtual functions
        void printBoard() override;
        void resetBoard() override;

        // public function that calls setShip a certain number of times
        void setShips();

        // function to update a tile on the player board when cpu fires
        void updateTile(int row, int col, bool is_hit);
};

#endif
