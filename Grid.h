#ifndef GRID_H
#define GRID_H

#include <iostream>

class Grid {
private:
    int grid[4][4];

public:
    Grid();
    int get(int row, int col) const;
    void set(int row, int col, int value);
    void clear(int row, int col);
    bool isSafe(int row, int col, int value) const;
    void print() const;
};

#endif // GRID_H
