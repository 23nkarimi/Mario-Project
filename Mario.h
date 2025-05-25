/*
Full name: Nima Karimi
Student ID: 2485949
Chapman Email: nikarimi@chapman.edu
Course number and section: CPSC-350-02
Assignment number: PA 2: Not So Super Mario Bros
*/
#ifndef MARIO_H
#define MARIO_H

#include <iostream>

class Mario{
    private:
        int lives = 0;
        int coins = 0;
        int powerLevel = 0;
    public:
        Mario();
        ~Mario();

        //setters
        void setLives(int lives); // adds and subtracts lives
        void setCoins(int coins); // adds and subtracts coins
        void setPowerLevel(int powerLevel); // adds and subtracts power levels
        //getters
        int getLives();
        int getPowerLevel();
        int getCoins();
};

#endif // MARIO_H