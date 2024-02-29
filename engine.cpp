// Name: James A. Chase
// File: engine.cpp
// Date: 27 February 2024
// Description: Implementation file for Engine class

#include <iostream>

#include "engine.h"

Engine::Engine() {
    game = new GameBoard();
    userboard = new PlayerBoard();
    enemyboard = new ShipBoard();
    isEnd = false;
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

    return (pBoard[row][col] == 'S') ? true : false;
}

bool Engine::enemyShipHit(int row, int col) {
    char (*eBoard)[10] = enemyboard->getBoard();

    return (eBoard[row][col] == 'S') ? true : false;
}

void Engine::runGame() {
    while (!isEnd) {
        int inpRow, inpCol;
        bool eHit;
        system("CLS");
        game->printBoard();
        std::cout << "Enter coordinate for shot [format-> ROW COL]: ";
        std::cin >> inpRow >> inpCol;

        eHit = enemyShipHit(inpRow, inpCol);
        game->updateTile(inpRow, inpCol, eHit);

        // isEnd = true;
    }
}

Engine::~Engine() {
    delete game;
    delete userboard;
    delete enemyboard;
}
