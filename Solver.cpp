#include "Solver.h"

Solver::Solver(Grid& grid, const Clues& clues) : grid(grid), clues(clues) {}

bool Solver::solve() {
    int row = -1, col = -1;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (grid.get(i, j) == 0) {
                row = i;
                col = j;
                break;
            }
        }
        if (row != -1) break;
    }

    if (row == -1) {
        return clues.validateFullBoard(grid);
    }

    for (int num = 1; num <= 4; ++num) {
        if (grid.isSafe(row, col, num)) {
            grid.set(row, col, num);

            if (solve()) {
                return true;
            }

            grid.clear(row, col);
        }
    }

    return false;
}
