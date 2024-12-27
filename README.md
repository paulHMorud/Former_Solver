# Former Solver

This program solves the NRK game "Former" by using DFS to find moves and making them until the game is completed. 
The program uses algorithms to analyze the game board, find clusters of tiles, and determine the predicted best moves to achieve the solution efficiently.
You have to hardcode the board you want to solve into the mainfile. 

## Table of Contents
- [Getting Started](#getting-started)
- [How to Run](#how-to-run)
- [Program Overview](#program-overview)
- [Output](#output)

## Getting Started

### Cloning the Repository
```
git clone https://github.com/paulHMorud/Former_Solver
cd formersolver
```

## How to Run
Example given using cmake.
1. Open a terminal and navigate to the directory containing the program files.
2. Run the `make` command to compile the program:
   ```
   make
   ```
3. Run the executable:
   ```
   ./myprogram
   ```

## Program Overview

### Main Components
The program is structured into several modules:
- **`board.h`**: Defines the structure of the game board and functions for manipulating it and analyzing it.
- **`print_colors.h`**: Handles colored output for a better visual representation of the board.
- **`solver.h`**: Contains algorithms for searching for the best move.

## Output
The program outputs:
- The current state of the board at each step.
- The number of moves required to solve the game.
- The sequence of moves as row-column pairs. (0-indexed)

