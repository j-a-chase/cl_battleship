#ifndef ENGINE_H
#define ENGINE_H

// library imports
#include <string>

// header imports
#include "gameboard.h"
#include "playerboard.h"
#include "shipboard.h"

// Engine class, runs the game
class Engine {
    private:
        // pointers for the different board objects needed
        GameBoard* game;
        PlayerBoard* userboard;
        ShipBoard* enemyboard;

        // gameflow variables
        bool isEnd;
        int turnCount;

        // stores user guesses
        std::string pGuesses[100];
        int pGuessIndex;

        // cpu guesses
        std::string eGuesses[100];
        int eGuessIndex;
        
        // runs initial setup functions for player board
        void setup();

        // runs main game loop
        void runGame();
        
        // runs enemy turn
        void enemyTurn();

        // functions to determine if player ships or enemy ships are hit
        bool playerShipHit(int row, int col);
        bool enemyShipHit(int row, int col);

        // determines if game has ended or not
        bool determineEndGame(bool playerTurn);
    public:
        // constructor
        Engine();

        // destructor
        ~Engine();
};

#endif
