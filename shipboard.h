// Name: James A. Chase
// File: shipboard.h
// Date: 26 February 2024
// Description: Header file for ShipBoard subclass

#ifndef SHIPBOARD_H
#define SHIPBOARD_H

#include "board.h"

class ShipBoard : public Board {
    public:
        void printBoard() override;
        void resetBoard() override;

        void placeShips();
};

#endif
