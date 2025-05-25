#include<iostream>
#include<fstream>
#include "FileProcessor.h"
FileProcessor::FileProcessor(){}
   
FileProcessor::FileProcessor(std::string inputFile, std::string outputFile){
    this->inputFile = inputFile;
    this->outputFile = outputFile;
}

FileProcessor::~FileProcessor(){
    delete level;
}

void FileProcessor::readFile(){
    std::ifstream input(inputFile); // open inputfile
    int levels, grid, lives, coinPercentage, nothingPercentage, goombaPercentage, koopaPercentage, mushroomPercentage; // Define separate variables
    if (input.is_open()) {
         //"""BEGIN CODE FROM CHAT GPT, PROMPT ASKED: The input file for this code will have one number every line. 
         //Each number needs to be stored in a different variable. How would I go about doing this?
        input >> levels >> grid >> lives >> coinPercentage >> nothingPercentage >> goombaPercentage >> koopaPercentage >> mushroomPercentage; // Read numbers into variables
        //"""END OF CODE FROM CHAT GPT"""
    }

    level = new Level();
    // storing data where it needs to go
    world.setNumOfLevels(levels);
    mario.setLives(lives);
    level->setCoinChance(coinPercentage);
    level->setNothingChance(nothingPercentage);
    level->setGoombaChance(goombaPercentage);
    level->setKoopaChance(koopaPercentage);
    level->setMushroomChance(mushroomPercentage);
    level->setGridSize(grid);
    world.createLevels(mario, level, outputFile);

    input.close();
}


