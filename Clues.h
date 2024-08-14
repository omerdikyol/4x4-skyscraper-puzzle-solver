#ifndef CLUES_H
#define CLUES_H

#include "Grid.h"

class Clues {
private:
    int clues[16];

public:
    Clues(int inputClues[16]);
    int getTop(int col) const;
    int getBottom(int col) const;
    int getLeft(int row) const;
    int getRight(int row) const;
    bool validateRow(const Grid& grid, int row) const;
    bool validateColumn(const Grid& grid, int col) const;
    bool validateFullBoard(const Grid& grid) const;
};

#endif // CLUES_H
