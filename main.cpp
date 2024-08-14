#include <iostream>
#include "SkyscraperPuzzle.h"

int main(int argc, char* argv[]) {
    if (argc != 17) {
        std::cerr << "Invalid number of arguments!" << std::endl;
        return 1;
    }

    int inputClues[16];
    for (int i = 0; i < 16; ++i) {
        inputClues[i] = std::atoi(argv[i + 1]);
    }

    SkyscraperPuzzle puzzle(inputClues);
    puzzle.solveAndPrint();

    return 0;
}
