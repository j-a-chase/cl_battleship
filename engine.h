#ifndef ENGINE_H
#define ENGINE_H

#include "gameboard.h"
#include "playerboard.h"
#include "shipboard.h"

class Engine {
    private:
        GameBoard* game;
        PlayerBoard* userboard;
        ShipBoard* enemyboard;
        bool isEnd;

        void setup();
        void runGame();
        bool playerShipHit(int row, int col);
        bool enemyShipHit(int row, int col);
    public:
        Engine();

        ~Engine();
};

#endif
