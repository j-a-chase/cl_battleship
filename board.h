#ifndef BOARD_H
#define BOARD_H

class Board {
    protected:
        char board[10][10];

    public:
        virtual void printBoard() = 0;
        virtual void resetBoard() = 0;
};

#endif
