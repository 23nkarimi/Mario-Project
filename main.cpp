#include "FileProcessor.h"

int main(int argc, char* argv[]){
    FileProcessor f(argv[1], argv[2]);
    f.readFile();
    return 0;
}
