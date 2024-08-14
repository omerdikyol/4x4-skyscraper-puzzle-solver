#ifndef SKYSCRAPERPUZZLE_H
#define SKYSCRAPERPUZZLE_H

#include "Grid.h"
#include "Clues.h"
#include "Solver.h"

class SkyscraperPuzzle {
private:
    Grid grid;
    Clues clues;
    Solver solver;

public:
    SkyscraperPuzzle(int inputClues[16]);
    void solveAndPrint();
    void printBoard() const;
};

#endif // SKYSCRAPERPUZZLE_H
