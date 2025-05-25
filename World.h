/*
Full name: Nima Karimi
Student ID: 2485949
Chapman Email: nikarimi@chapman.edu
Course number and section: CPSC-350-02
Assignment number: PA 2: Not So Super Mario Bros
*/
#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include "Level.h"
#include "GameSim.h"
#include "Mario.h"

class World{
    private:
    int numLevels = 0;
    public:
        World();
        ~World();

        void setNumOfLevels(int numLevels);
        void createLevels(Mario mario, Level*level, std::string outputFile);
};

#endif // WORLD_H