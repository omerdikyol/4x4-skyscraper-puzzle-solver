#include "Grid.h"

Grid::Grid() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            grid[i][j] = 0;
        }
    }
}

int Grid::get(int row, int col) const {
    return grid[row][col];
}

void Grid::set(int row, int col, int value) {
    grid[row][col] = value;
}

void Grid::clear(int row, int col) {
    grid[row][col] = 0;
}

bool Grid::isSafe(int row, int col, int value) const {
    for (int i = 0; i < 4; i++) {
        if (grid[row][i] == value || grid[i][col] == value) {
            return false;
        }
    }
    return true;
}

void Grid::print() const {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << "[" << grid[i][j] << "]";
        }
        std::cout << std::endl;
    }
}
