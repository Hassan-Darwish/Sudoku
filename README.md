# Sudoku Game in C++

## Description

The Sudoku Game project is a console-based implementation of the popular Sudoku puzzle, developed in C++. It demonstrates a modular, object-oriented design (OOP) and leverages the C++ Standard Template Library (STL). 

## Features

* 9x9 Sudoku board with rule validation
* User-friendly console interface
* Game loop with menu interaction
* Custom exception system for input and game rule errors
* Backtracking-based Sudoku solver
* Modular code structure with separate classes for board, solver, and game management

## Menu Options

Upon launching, the game presents a menu with the following options:

```
1) Enter a move
2) Solve automatically
5) Exit
```

## How to Build

### Requirements:

* C++17 or higher
* CMake 3.8+

### Instructions:

```bash
cmake -S . -B build
cmake --build build
./build/SudokuProject
```

## Project Structure

```
├── main.cpp                     # Program entry point
├── SudokuBoard.hpp/.cpp        # Board representation & validation
├── SudokuGame.hpp/.cpp         # Game flow and UI
├── SudokuSolver.hpp/.cpp       # Backtracking puzzle solver
├── CMakeLists.txt              # Build configuration
```

## Code Overview

### Class: `SudokuBoard`

* Stores the 9x9 grid
* Checks legal moves
* Throws exceptions for invalid operations
* Prints the board to the console

### Class: `SudokuSolver`

* Uses recursive backtracking
* Validates placement using board methods

### Class: `SudokuGame`

* Manages game loop and input
* Handles user moves and errors

## License

MIT License

```
MIT License

Copyright (c) 2025 Hassan Darwish

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
```

## Author

**Hassan Darwish**
