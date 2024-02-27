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
