#ifndef ENGINE_H
#define ENGINE_H

#include <string>

#include "gameboard.h"
#include "playerboard.h"
#include "shipboard.h"

class Engine {
    private:
        GameBoard* game;
        PlayerBoard* userboard;
        ShipBoard* enemyboard;
        bool isEnd;
        std::string guesses[100];
        int guess_i;
        int turnCount;

        void setup();
        void runGame();
        bool playerShipHit(int row, int col);
        bool enemyShipHit(int row, int col);
        void enemyTurn();

        bool determineEndGame(bool isPlayer);
    public:
        Engine();

        ~Engine();
};

#endif
