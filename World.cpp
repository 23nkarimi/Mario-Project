/*
Full name: Nima Karimi
Student ID: 2485949
Chapman Email: nikarimi@chapman.edu
Course number and section: CPSC-350-02
Assignment number: PA 2: Not So Super Mario Bros
*/
#include "World.h"
#include <fstream>

World::World(){}

World::~World(){}

void World::setNumOfLevels(int numLevels){
    this->numLevels += numLevels;
}

void World::createLevels(Mario mario, Level* level, std::string outputFile){
    // Clear the file at the start of the simulation (truncate mode)
    std::ofstream outFile(outputFile, std::ios::trunc);
    outFile.close(); // Close immediately to avoid conflicts

    bool won = false;
    int totalMoves = 0;

    for(int i = 0; i < numLevels; i++){
        // checking to see if it is the last level
        if(i == (numLevels - 1)){
            level->setGrid(true);
        }
        else{
            level->setGrid(false);
        }

        GameSim game(level, mario); // Creating the game
        game.setOutputFile(outputFile); 
        won = game.gameLoop(i); // Calling the game loop

        totalMoves += game.getMovesCounter();

        if(!won){
            break; // If the player loses, exit the loop early
        }
    }

    //"""BEGIN CODE FROM CHAT GPT, PROMPT ASKED: The win and lose message is on the top, how would I change it so that it is on the bottom? 
    std::ofstream finalOutFile(outputFile, std::ios::app);
    if (!won) {
        finalOutFile << "\nWE LOST THE GAME :(" << std::endl;
    } else {
        finalOutFile << "\nWE WON THE GAME :)" << std::endl;
    }
    finalOutFile << "It took " << totalMoves << " moves.";
    finalOutFile.close(); 
    //"""END OF CODE FROM CHAT GPT"""
}
