// Name: James A. Chase
// File: shipboard.h
// Date: 26 February 2024
// Description: Header file for ShipBoard subclass

#ifndef SHIPBOARD_H
#define SHIPBOARD_H

// header imports
#include "board.h"

// represents cpu's board, inherits from Board parent class
class ShipBoard : public Board {
    public:
        // constructor
        ShipBoard();

        // override parent virtual function
        void resetBoard() override;

        // placeShips method to place the CPU ships
        void placeShips();
};

#endif
