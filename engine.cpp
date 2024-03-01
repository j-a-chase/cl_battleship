// Name: James A. Chase
// File: engine.cpp
// Date: 27 February 2024
// Description: Implementation file for Engine class

// library imports
#include <iostream>
#include <string>
#include <ctime>

// header imports
#include "engine.h"

// constructor implementation
Engine::Engine() {
    // intialize new objects into memory
    game = new GameBoard();
    userboard = new PlayerBoard();
    enemyboard = new ShipBoard();

    // initialize gameflow variables
    isEnd = false;
    turnCount = 1;

    // initialize guess array indices
    pGuessIndex = 0;
    eGuessIndex = 0;

    // run setup
    setup();
}

// setup implementation
void Engine::setup() {
    // print welcome message
    std::cout << "Welcome to Battleship!\n";

    // print initial board and have user set ships
    userboard->printBoard();
    userboard->setShips();

    // show user their board before continuing the game
    std::cout << "\n\n";
    std::cout << "This is your gameboard ^\n";
    system("pause");

    // begin main game loop
    runGame();
}

// playerShipHit implementation
bool Engine::playerShipHit(int row, int col) {
    // get userboard
    char (*pBoard)[10] = userboard->getBoard();

    // determine if targetted tile is a ship tile
    return pBoard[row][col] == 'S';
}

// enemyShipHit implementation
bool Engine::enemyShipHit(int row, int col) {
    // get enemyboard
    char (*eBoard)[10] = enemyboard->getBoard();

    // determine if targetted tile is a ship tile
    return eBoard[row][col] == 'S';
}

// enemyTurn implementation
void Engine::enemyTurn() {
    // stores selected row and column
    int row, col;

    // stores indicator if player ship was hit
    bool is_hit;

    // determines if randomly selected coordinates are valid
    bool valid = false;

    // string to hold cpu shot guess
    std::string guess;

    // initialize random seed
    std::srand(std::time(nullptr));

    // while not valid guess
    while (!valid) {
        // randomly select a row and column
        row = std::rand() % 10;
        col = std::rand() % 10;

        // convert to string and search guesses array for guess, keep looping if duplicate is found
        guess = std::to_string(row) + " " + std::to_string(col);
        valid = true;
        for (int i = 0; i < std::size(eGuesses); i++) {
            if (eGuesses[i] == guess) {
                valid = false;
                break;
            }
        }
    }

    // add guess to guesses array and increment guess index
    eGuesses[eGuessIndex++] += guess;

    // determine if player ship was hit
    is_hit = playerShipHit(row, col);

    // update userboard tile
    userboard->updateTile(row, col, is_hit);

    // print updated user board with enemy shot
    system("CLS");
    std::cout << "Turn " << turnCount << "\n";
    userboard->printBoard();
    std::cout << "\n\nEnemy shot: " << row << " " << col << "\n";
    system("pause");
}

// determineEndGame implementation
bool Engine::determineEndGame(bool playerTurn) {
    // get user and game boards
    char (*player)[10] = userboard->getBoard();
    char (*cpu)[10] = game->getBoard();

    // keep track of how many ship tiles have been hit
    int eHitCount, pHitCount;

    // initialize to zero, loop through both boards and increment when hits are found
    eHitCount = pHitCount = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (player[i][j] == 'X') pHitCount++;
            if (cpu[i][j] == 'O') eHitCount++;
        }
    }

    // if its the player's turn, return if they've won
    if (playerTurn) return eHitCount == 14;
    
    // cpu turn, return if cpu won
    return pHitCount == 14;
}

// runGame implementation
void Engine::runGame() {
    // while game is not over
    while (!isEnd) {
        // hold user input for row and column
        int inpRow, inpCol;

        // hold if enemy ship was hit
        bool eHit;

        // determines if user input is valid
        bool valid = false;

        // holds string conversion of user guess
        std::string guess;

        // print user board and turn count
        system("CLS");
        std::cout << "Turn " << turnCount << "\n";
        game->printBoard();

        // while input isn't valid
        while (!valid) {
            // get input
            std::cout << "\n\nEnter coordinate for shot [format-> ROW COL]: ";
            std::cin >> inpRow >> inpCol;

            // hold string converted input
            guess = std::to_string(inpRow) + " " + std::to_string(inpCol);

            // search for duplicate, print warning message if found and loop again
            valid = true;
            for (int i = 0; i < std::size(pGuesses); i++) {
                if (pGuesses[i] == guess) {
                    std::cout << "\nCannot shoot same tile twice!\n";
                    valid = false;
                    break;
                }
            }
        }

        // add guess to guesses array and increment guess index
        pGuesses[pGuessIndex++] = guess;

        // determine if enemy ship was hit
        eHit = enemyShipHit(inpRow, inpCol);

        // update gameboard tile appropriately
        game->updateTile(inpRow, inpCol, eHit);

        // determine if the game is over after user's turn
        isEnd = determineEndGame(true);
        if (isEnd) {
            // end game with victory message
            system("CLS");
            game->printBoard();
            std::cout << "\n\nYou win!!!\n";
            return;
        }

        // print updated board after shot
        system("CLS");
        std::cout << "Turn " << turnCount << "\n";
        game->printBoard();
        std::cout << "\n\nYour shot: " << inpRow << " " << inpCol << "\n";
        system("pause");

        // take enemy turn
        enemyTurn();

        // increment turn count
        turnCount++;
        
        // determine if game is over after cpu turn
        isEnd = determineEndGame(false);
        if (isEnd) {
            // print loss message
            system("CLS");
            userboard->printBoard();
            std::cout << "\n\nYou lose!!!\n";
            return;
        }
    }
}

// destructor implementation
Engine::~Engine() {
    // free up memory after assets are no longer needed
    delete game;
    delete userboard;
    delete enemyboard;
}
