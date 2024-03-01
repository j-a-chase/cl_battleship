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
        int turnCount;

        std::string pGuesses[100];
        int pGuessIndex;

        std::string eGuesses[100];
        int eGuessIndex;
        
        void setup();
        void runGame();
        void enemyTurn();

        bool playerShipHit(int row, int col);
        bool enemyShipHit(int row, int col);
        bool determineEndGame(bool isPlayer);
    public:
        Engine();

        ~Engine();
};

#endif
