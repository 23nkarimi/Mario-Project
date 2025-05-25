/*
Full name: Nima Karimi
Student ID: 2485949
Chapman Email: nikarimi@chapman.edu
Course number and section: CPSC-350-02
Assignment number: PA 2: Not So Super Mario Bros
*/
#include "Level.h"

Level::Level(){
    srand(time(0));
}

Level::~Level(){
    for (int i = 0; i < gridSize; i++) {
        delete[] grid[i];  // Free each row
    }
    delete[] grid;  // Free grid array
}

void Level::setGridSize(int size){
    gridSize = size;
}

void Level::setCoinChance(int percentage){
    coinChance = percentage;
}

void Level::setNothingChance(int percentage){
    nothingChance = percentage;
}

void Level::setGoombaChance(int percentage){
    goombaChance = percentage;
}

void Level::setKoopaChance(int percentage){
    koopaChance = percentage;
}

void Level::setMushroomChance(int percentage){
    mushroomChance = percentage;
}

int Level::getGridSize(){
    return gridSize;
}

int Level::getMarioR(){
    return marioR;
}

int Level::getMarioC(){ 
    return marioC;
}

char** Level::getGrid() { 
    return grid; 
}

void Level::setGrid(bool lastLevel){
    //creating the grid
    grid = new char*[gridSize];

    //loop that fills the grid randomly with items and enemies
    for(int i = 0; i < gridSize; i++){
        grid[i] = new char[gridSize];
        for(int j = 0; j < gridSize; j++){
            int randomNum = rand() % 100 + 1;
            if(randomNum <= coinChance){
                grid[i][j] = 'c';
            }
            else if(randomNum <= (coinChance + nothingChance)){
                grid[i][j] = 'x';
            }
            else if(randomNum <= (coinChance + nothingChance + goombaChance)){
                grid[i][j] = 'g';
            }
            else if(randomNum <= (coinChance + nothingChance + goombaChance + koopaChance)){
                grid[i][j] = 'k';
            }
            else{
                grid[i][j] = 'm';
            }
        }
    }

    //setting up the random posistions for mario, the warp pipe, and the boss
    int marioRPos = rand() % gridSize;
    int marioCPos = rand() % gridSize;
    int bossRPos = rand() % gridSize;
    int bossCPos = rand() % gridSize;
    int pipeRPos = rand() % gridSize;
    int pipeCPos = rand() % gridSize;

    //spawning mario and storing his position
    grid[marioRPos][marioCPos] = 'H';
    marioR = marioRPos;
    marioC = marioCPos;

    //making sure the boss is not in the same place as mario
    do {
        bossRPos = rand() % gridSize;
        bossCPos = rand() % gridSize;
    } while (marioRPos == bossRPos && marioCPos == bossCPos);

    //spawning the boss
    grid[bossRPos][bossCPos] = 'b';
    
    //making sure the warp pipe is not in the same place as mario and the boss
    //only spawing a warp pipe if it is not the last level
    if(lastLevel == false){
        do {
            pipeRPos = rand() % gridSize;
            pipeCPos = rand() % gridSize;
        } while ((pipeRPos == marioRPos && pipeCPos == marioCPos) ||
                (pipeRPos == bossRPos && pipeCPos == bossCPos));    

        grid[pipeRPos][pipeCPos] = 'w';
    }

}
