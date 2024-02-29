// Name: James A. Chase
// File: shipboard.h
// Date: 26 February 2024
// Description: Header file for ShipBoard subclass

#ifndef SHIPBOARD_H
#define SHIPBOARD_H

#include "board.h"

class ShipBoard : public Board {
    public:
        ShipBoard();

        void printBoard() override;
        void resetBoard() override;

        char (*getBoard())[10] { return board; }

        void placeShips();
};

#endif
