#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "board.h"

class GameBoard : public Board {
    public:
        void printBoard() override;
        void resetBoard() override;
        
        void updateTile(int row, int col);
};

#endif
