// Name: James A. Chase
// File: playerboard.h
// Date: 26 February 2024
// Description: Header file for PlayerBoard class

#ifndef PLAYERBOARD_H
#define PLAYERBOARD_H

#include "board.h"

class PlayerBoard : public Board {
    private:
        void setShip(int size);

    public:
        PlayerBoard();
    
        void printBoard() override;
        void resetBoard() override;

        void setShips();
        void updateTile(int row, int col, bool is_hit);
};

#endif
