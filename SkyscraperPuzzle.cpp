#include "SkyscraperPuzzle.h"
#include <iostream>

SkyscraperPuzzle::SkyscraperPuzzle(int inputClues[16]) : clues(inputClues), solver(grid, clues) {}

void SkyscraperPuzzle::solveAndPrint() {
    if (solver.solve()) {
        std::cout << "Solved puzzle:" << std::endl;
        printBoard();
    } else {
        std::cout << "No solution found." << std::endl;
    }
}

void SkyscraperPuzzle::printBoard() const {
    std::cout << "  ";
    for (int i = 0; i < 4; ++i) {
        std::cout << " " << clues.getTop(i) << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 4; ++i) {
        std::cout << clues.getLeft(i) << " ";
        for (int j = 0; j < 4; ++j) {
            std::cout << "[" << grid.get(i, j) << "]";
        }
        std::cout << " " << clues.getRight(i) << std::endl;
    }

    std::cout << "  ";
    for (int i = 0; i < 4; ++i) {
        std::cout << " " << clues.getBottom(i) << " ";
    }
    std::cout << std::endl;
}
