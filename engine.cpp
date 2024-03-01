// Name: James A. Chase
// File: engine.cpp
// Date: 27 February 2024
// Description: Implementation file for Engine class

#include <iostream>
#include <string>
#include <ctime>

#include "engine.h"

Engine::Engine() {
    game = new GameBoard();
    userboard = new PlayerBoard();
    enemyboard = new ShipBoard();
    isEnd = false;
    guess_i = 0;
    turnCount = 1;
    setup();
}

void Engine::setup() {
    std::cout << "Welcome to Battleship!\n";
    userboard->printBoard();
    userboard->setShips();
    std::cout << "\n\n";
    std::cout << "This is your gameboard ^\n";
    system("pause");
    runGame();
}

bool Engine::playerShipHit(int row, int col) {
    char (*pBoard)[10] = userboard->getBoard();

    return pBoard[row][col] == 'S';
}

bool Engine::enemyShipHit(int row, int col) {
    char (*eBoard)[10] = enemyboard->getBoard();

    return eBoard[row][col] == 'S';
}

void Engine::enemyTurn() {
    int row, col;
    bool is_hit;
    bool valid = false;
    std::string guess;
    std::srand(std::time(nullptr));

    while (!valid) {
        row = std::rand() % 10;
        col = std::rand() % 10;

        guess = std::to_string(row) + " " + std::to_string(col);
        valid = true;
        for (int i = 0; i < std::size(guesses); i++) {
            if (guesses[i] == guess) {
                valid = false;
                break;
            }
        }
    }

    guesses[guess_i++] += guess;

    is_hit = playerShipHit(row, col);
    userboard->updateTile(row, col, is_hit);

    system("CLS");
    std::cout << "Turn " << turnCount << "\n";
    userboard->printBoard();
    std::cout << "\n\nEnemy shot: " << row << " " << col << "\n";
    system("pause");
}

bool Engine::determineEndGame(bool playerTurn) {
    char (*player)[10] = userboard->getBoard();
    char (*cpu)[10] = game->getBoard();

    int eHitCount, pHitCount;
    eHitCount = pHitCount = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (player[i][j] == 'X') pHitCount++;
            if (cpu[i][j] == 'O') eHitCount++;
        }
    }

    if (playerTurn) return eHitCount == 14;
    return pHitCount == 14;
}

void Engine::runGame() {
    while (!isEnd) {
        int inpRow, inpCol;
        bool eHit;
        system("CLS");
        std::cout << "Turn " << turnCount << "\n";
        game->printBoard();
        std::cout << "\n\nEnter coordinate for shot [format-> ROW COL]: ";
        std::cin >> inpRow >> inpCol;

        eHit = enemyShipHit(inpRow, inpCol);
        game->updateTile(inpRow, inpCol, eHit);

        isEnd = determineEndGame(true);
        if (isEnd) {
            system("CLS");
            game->printBoard();
            std::cout << "\n\nYou win!!!\n";
            return;
        }

        system("CLS");
        std::cout << "Turn " << turnCount << "\n";
        game->printBoard();
        std::cout << "\n\nYour shot: " << inpRow << " " << inpCol << "\n";
        system("pause");

        enemyTurn();
        turnCount++;
        
        isEnd = determineEndGame(false);
        if (isEnd) {
            system("CLS");
            userboard->printBoard();
            std::cout << "\n\nYou lose!!!\n";
            return;
        }
    }
}

Engine::~Engine() {
    delete game;
    delete userboard;
    delete enemyboard;
}
