# Skyscraper Puzzle Solver

Example demo of the game: https://www.puzzle-skyscrapers.com/
- ![image](https://github.com/user-attachments/assets/3876912f-d560-4ea9-bf7d-87e173bdbbfd)


## Overview

This repository contains a C++ implementation of a Skyscraper Puzzle Solver for a 4x4 grid. The puzzle is a logic-based puzzle played on a grid, where the player must place skyscrapers of varying heights such that they satisfy visibility constraints given as clues on the edges of the grid.

The project is organized in a modular way with distinct classes for managing the grid, clues, and solving logic, promoting a clear separation of concerns and enhancing code maintainability.

## Files and Structure

- **`main.cpp`**: The entry point of the application. It handles command-line input and initializes the puzzle-solving process.

- **`Grid.h` & `Grid.cpp`**: These files define and implement the `Grid` class, which manages the 4x4 grid of the skyscraper puzzle. The class includes methods for setting and getting grid values, checking if a move is safe, and printing the grid.

- **`Clues.h` & `Clues.cpp`**: These files define and implement the `Clues` class, which encapsulates the clues provided at the borders of the grid. It provides methods to validate rows and columns based on the clues.

- **`SkyscraperPuzzle.h` & `SkyscraperPuzzle.cpp`**: These files define and implement the `SkyscraperPuzzle` class, which coordinates the solving process by utilizing the `Grid` and `Clues` classes. It includes the main puzzle-solving algorithm and printing functions.

- **`Solver.h` & `Solver.cpp`**: These files define and implement the `Solver` class, which contains the backtracking algorithm used to solve the puzzle. It attempts to fill the grid based on the clues and validates each step using the logic defined in the `Clues` class.

## How to Build and Run

### Prerequisites

- A C++ compiler that supports C++11 or higher.
- A terminal or command prompt to run the application.

### Build Instructions

1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd <repository-directory>
   ```

2. Compile the project:
   ```bash
   g++ main.cpp Grid.cpp Clues.cpp SkyscraperPuzzle.cpp Solver.cpp -o skyscraper_solver
   ```

3. Run the executable with command-line arguments for the clues:
   ```bash
    ./skyscraper_solver col1up col2up col3up col4up col1down col2down col3down col4down row1left row2left row3left row4left row1right row2right row3right row4right
   ```

### Example Usage
   ```bash
    ./skyscraper_solver 4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2
   ```

Will attempt to solve a 4x4 puzzle with the given clues and print the solution if found.

## Code Structure

### Grid Class
The Grid class is responsible for managing the puzzle's 4x4 grid:

set(int row, int col, int value): Sets the value at a specific cell in the grid.
get(int row, int col): Retrieves the value at a specific cell.
isSafe(int row, int col, int value): Checks if placing a value in a cell is valid according to the grid's current state.
print(): Prints the grid to the console.

### Clues Class
The Clues class manages the clues provided for the puzzle:

- getTop(int col), getBottom(int col), getLeft(int row), getRight(int row): Retrieve the clues for the respective row or column.
- validateRow(const Grid& grid, int row): Validates a row based on the clues.
- validateColumn(const Grid& grid, int col): Validates a column based on the clues.
- validateFullBoard(const Grid& grid): Validates the entire grid.

### SkyscraperPuzzle Class
The SkyscraperPuzzle class integrates the grid and clues to solve the puzzle:

- solveAndPrint(): Solves the puzzle and prints the result.
- printBoard(): Prints the grid along with the clues.

### Solver Class
The Solver class handles the backtracking algorithm:

- solve(): Attempts to solve the grid by filling in values while respecting the clues.

## Contributions
Contributions are welcome! Feel free to submit a pull request or open an issue to improve the solver or fix any bugs.

