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
}

void Engine::runGame() {
    std::cout << "Welcome to Battleship!\n";
    userboard->printBoard();
    userboard->setShips();
    std::cout << "\n\n";
    userboard->printBoard();
    std::cout << "\n";
    enemyboard->printBoard();
    std::cout << "\n";
    game->printBoard();
}

Engine::~Engine() {
    delete game;
    delete userboard;
    delete enemyboard;
}
