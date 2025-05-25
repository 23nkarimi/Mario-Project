/*
Full name: Nima Karimi
Student ID: 2485949
Chapman Email: nikarimi@chapman.edu
Course number and section: CPSC-350-02
Assignment number: PA 2: Not So Super Mario Bros
*/
#include "Mario.h"

Mario::Mario(){}

Mario::~Mario(){}

void Mario::setLives(int lives){
    this->lives += lives;
}

void Mario::setCoins(int coins){
    this->coins += coins;
    if(this->coins == 20){
        lives += 1;
        this->coins = 0;
    }
}

void Mario::setPowerLevel(int powerLevel){
    if(this->powerLevel < 3){
        this->powerLevel += powerLevel;
    }

    if(this->powerLevel < 0){
        lives -= 1;
        this->powerLevel = 0;
    }
}

int Mario::getLives(){
    return lives;
}

int Mario::getPowerLevel(){
    return powerLevel;
}

int Mario::getCoins(){
    return coins;
}

