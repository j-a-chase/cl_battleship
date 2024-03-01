// Name: James A. Chase
// File: validation.cpp
// Date: 29 February 2024
// Description: Implementation file for custom input validation function

// library imports
#include <iostream>

// header imports
#include "validation.h"

// validateInput implemention
int validateInput(std::string message) {
    // holds user input
    int input;

    // represents if input is valid
    bool valid = false;

    // print message
    std::cout << message;
    
    // while input isn't valid
    while (!valid) {
        // if input is valid, break loop, else clear buffer, print warning and loop again
        if (std::cin >> input) valid = true;
        else {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Please enter an integer!\n> ";
        }
    }

    // ensure buffer is clear for next input
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');

    // return user input
    return input;
}