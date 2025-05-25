/*
Full name: Nima Karimi
Student ID: 2485949
Chapman Email: nikarimi@chapman.edu
Course number and section: CPSC-350-02
Assignment number: PA 2: Not So Super Mario Bros
*/
#ifndef GAMESIM_H
#define GAMESIM_H

#include <iostream>
#include "Level.h"
#include "Mario.h"

class GameSim{
    private:
        Level* level;
        char** grid;
        Mario mario;
        bool isRunning = true; 
        int gridSize;
        int heroR; // mario's row position
        int heroC; // mario's column position
        char item = 'x';
        std::string outputFile;
        std::string direction;
        int counter = 0;
        int movesCounter = 0;
    public:
        GameSim();
        GameSim(Level* level, Mario mario); //constructor
        ~GameSim(); //destructor

        void move(char replaceWith); // moves mario within the array
        bool battle(int winChance); // handles enemy encounters
        bool gameLoop(int levelNum); // loops through mario's actions and returns if he won or not
        void setOutputFile(std::string outputFile); // writes the output file
        int getMovesCounter();
};

#endif // GAMESIM_H