#ifndef BOARD_H
#define BOARD_H

class Board {
    private:
        char board[10][10];

    public:
        virtual void printBoard() = 0;
        virtual void updateTile(int row, int col) = 0;
        virtual void resetBoard() = 0;
};

#endif
