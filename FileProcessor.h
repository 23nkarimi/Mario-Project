#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H


#include <iostream>
#include "World.h"
#include "Level.h"
#include "Mario.h"

class FileProcessor{
    private:
        World world;
        Level* level;
        Mario mario;
        std::string inputFile;
        std::string outputFile;
    public:
        FileProcessor();

        FileProcessor(std::string inputFile, std::string outputFile);

        ~FileProcessor();

        void readFile(); // reads file then stores and distributes data
};

#endif // FILEPROCESSOR_H
