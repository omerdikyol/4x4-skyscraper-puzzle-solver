#include "Clues.h"

Clues::Clues(int inputClues[16]) {
    for (int i = 0; i < 16; i++) {
        clues[i] = inputClues[i];
    }
}

int Clues::getTop(int col) const {
    return clues[col];
}

int Clues::getBottom(int col) const {
    return clues[4 + col];
}

int Clues::getLeft(int row) const {
    return clues[8 + row];
}

int Clues::getRight(int row) const {
    return clues[12 + row];
}

bool Clues::validateRow(const Grid& grid, int row) const {
    int leftClue = getLeft(row);
    int rightClue = getRight(row);
    int visibleFromLeft = 0, maxFromLeft = 0;
    int visibleFromRight = 0, maxFromRight = 0;

    for (int j = 0; j < 4; j++) {
        int value = grid.get(row, j);
        if (value > maxFromLeft) {
            maxFromLeft = value;
            visibleFromLeft++;
        }
    }

    for (int j = 3; j >= 0; j--) {
        int value = grid.get(row, j);
        if (value > maxFromRight) {
            maxFromRight = value;
            visibleFromRight++;
        }
    }

    return (leftClue == 0 || leftClue == visibleFromLeft) &&
           (rightClue == 0 || rightClue == visibleFromRight);
}

bool Clues::validateColumn(const Grid& grid, int col) const {
    int topClue = getTop(col);
    int bottomClue = getBottom(col);
    int visibleFromTop = 0, maxFromTop = 0;
    int visibleFromBottom = 0, maxFromBottom = 0;

    for (int i = 0; i < 4; i++) {
        int value = grid.get(i, col);
        if (value > maxFromTop) {
            maxFromTop = value;
            visibleFromTop++;
        }
    }

    for (int i = 3; i >= 0; i--) {
        int value = grid.get(i, col);
        if (value > maxFromBottom) {
            maxFromBottom = value;
            visibleFromBottom++;
        }
    }

    return (topClue == 0 || topClue == visibleFromTop) &&
           (bottomClue == 0 || bottomClue == visibleFromBottom);
}

bool Clues::validateFullBoard(const Grid& grid) const {
    for (int i = 0; i < 4; i++) {
        if (!validateRow(grid, i) || !validateColumn(grid, i)) {
            return false;
        }
    }
    return true;
}
