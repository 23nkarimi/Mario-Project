#include "GameSim.h"
#include <fstream>
#include "FileProcessor.h"

GameSim::GameSim(){}

GameSim::GameSim(Level* level, Mario mario) {
    srand(time(0));
    this->level = level;
    this->mario = mario;
    gridSize = level->getGridSize();
    heroR = level->getMarioR();
    heroC = level->getMarioC();
    grid = level->getGrid();
}

void GameSim::setOutputFile(std::string outputFile){
    this->outputFile = outputFile;
}


GameSim::~GameSim(){}

void GameSim::move(char replaceWith) {
    char currentItem = grid[heroR][heroC]; // keeps track of the item/enemy mario encountered
    grid[heroR][heroC] = replaceWith; //ensure that Mario's previous position is reset
    int randomNum = rand() % 100 + 1;
    int nextR = heroR; // for updating mario's row position
    int nextC = heroC; // for updating mario's column position

    // moving down
    if (randomNum <= 25) {
        direction = "DOWN.";
        nextR = (heroR + 1) % gridSize; 
    } 
    // moving right
    else if (randomNum <= 50) {
        direction = "RIGHT.";
        nextC = (heroC + 1) % gridSize; 
    } 
    // moving up
    else if (randomNum <= 75) {
        direction = "UP.";
        nextR = (heroR - 1 + gridSize) % gridSize; 
    } 
    // moving left
    else {
        direction = "LEFT.";
        nextC = (heroC - 1 + gridSize) % gridSize;
    }

    heroR = nextR;
    heroC = nextC;

    item = grid[heroR][heroC]; // store item
    grid[heroR][heroC] = 'H'; // update Mario's position
}

bool GameSim::battle(int winChance){
    return (rand() % 100 + 1) <= winChance;
}

bool GameSim::gameLoop(int levelNum){
    //"""BEGIN CODE FROM CHAT GPT, PROMPT ASKED: How to continuously write into a file in c++
    std::ofstream outFile(outputFile, std::ios::app);
    //"""END OF CODE FROM CHAT GPT"""
    if (!outFile.is_open()) return false; // making sure the output file is open

     // printing out the  initial grid
     outFile << "==========" << std::endl;
     for(int i = 0; i < gridSize; i++){
         for(int j = 0; j < gridSize; j++){
             outFile << grid[i][j];
         }
         outFile << "\n";
     }
     outFile << "==========" << std::endl;
    
     bool won = true;
    // game loop
    while(isRunning == true){
        movesCounter += 1;
        bool willMove = true;

        outFile << "Level: " << levelNum << ". ";
        outFile << "Mario is at position: (" << heroR << "," << heroC << "). ";
        outFile << "Mario is at power level " << mario.getPowerLevel() << ". ";
        
        // mushroom
        if (item == 'm') {
            mario.setPowerLevel(1);
            outFile << "Mario ate a mushroom. ";
            move('x');
        // coin
        } else if (item == 'c') {
            mario.setCoins(1);
            outFile << "Mario collected a coin. ";
            move('x');
        // goomba
        } else if (item == 'g') {
            if (battle(80)) {
                outFile << "Mario encountered a goomba and won. ";
                move('x');
                counter += 1;
            } else {
                mario.setPowerLevel(-1);
                outFile << "Mario encountered a goomba and lost. ";
                move('g');
                counter = 0;
            }
        // koopa
        } else if (item == 'k') {
            if (battle(65)) {
                outFile << "Mario encountered a koopa and won. ";
                move('x');
                counter += 1;
            } else {
                mario.setPowerLevel(-1);
                outFile << "Mario encountered a koopa and lost. ";
                move('k');
                counter = 0;
            }
        // boss
        } else if (item == 'b') {
            if (battle(50)) {
                outFile << "Mario encountered the boss and won. Level over. ";
                isRunning = false;
                willMove = false;
                counter += 1;
            } else {
                if(mario.getPowerLevel() <= 0 && mario.getLives() <= 1){
                    outFile << "Mario is too weak to continue the battle. ";
                    mario.setLives(-1);
                    isRunning = false;
                    willMove = false;
                    won = false;
                    counter = 0;
                } else {
                    mario.setPowerLevel(-2);
                    outFile << "Mario encountered the boss and lost. Try again. ";
                    willMove = false;
                    counter = 0;
                }
            }
        // warp pipe
        } else if (item == 'w') {
            outFile << "Mario found a warp pipe and continued to the next level. ";
            isRunning = false;
            willMove = false;
        // empty space
        } else {
            outFile << "Mario visited an empty space. ";
            move('x');
        }

        if(mario.getLives() == 0){
            outFile << "Mario has 0 lives left." << std::endl;
            isRunning = false;
            willMove = false;
            won = false;
        }

        if(counter >= 7){
            mario.setLives(1);
            counter = 0;
        }

        outFile << "Mario has " << mario.getLives() << " lives left. ";
        outFile << "Mario has " << mario.getCoins() << " coins. ";
        if(willMove == true){
            outFile << "Mario will move " << direction << std::endl;
        }
        else{
            outFile << "Mario will stay put. " << std::endl;
            if(isRunning == false){
                break;
            }
        }

      // printing out the grid
      outFile << "==========\n";
      for(int i = 0; i < gridSize; i++){
          for(int j = 0; j < gridSize; j++){
              outFile << grid[i][j];
          }
          outFile << "\n";
      }
      outFile << "==========\n";
    }

    if( won == true){
        return true;
    }
    else{
        return false;
    }

    //outFile.close();
}

int GameSim::getMovesCounter(){
    return movesCounter;
}
