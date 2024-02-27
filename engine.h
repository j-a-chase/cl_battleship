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

    public:
        Engine();

        void runGame();

        ~Engine();
};

#endif
