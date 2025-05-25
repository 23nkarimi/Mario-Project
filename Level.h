/*
Full name: Nima Karimi
Student ID: 2485949
Chapman Email: nikarimi@chapman.edu
Course number and section: CPSC-350-02
Assignment number: PA 2: Not So Super Mario Bros
*/
#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>

class Level{
    private:
        int gridSize;
        char** grid;
        int coinChance;
        int nothingChance;
        int goombaChance;
        int koopaChance;
        int mushroomChance;
        int marioR;
        int marioC;
    public:
        Level();
        ~Level();

        // setters
        void setGridSize(int size);
        void setCoinChance(int percentage);
        void setNothingChance(int percentage);
        void setGoombaChance(int percentage);
        void setKoopaChance(int percentage);
        void setMushroomChance(int percentage);
        //getters
        int getGridSize();
        int getMarioR();
        int getMarioC();
        char** getGrid();

        void setGrid(bool lastLevel); // creates the level grid 
};

#endif // LEVEL_H
