#ifndef SOLVER_H
#define SOLVER_H

#include "Grid.h"
#include "Clues.h"

class Solver {
private:
    Grid& grid;
    const Clues& clues;

public:
    Solver(Grid& grid, const Clues& clues);
    bool solve();
};

#endif // SOLVER_H
