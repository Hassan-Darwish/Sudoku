#pragma once
#include "SudokuBoard.hpp"

class SudokuSolver {
public:
    // Entry point to solving
    bool solve(SudokuBoard& board);

private:
    // Internal recursive solver
    bool solveRecursive(SudokuBoard& board, int row, int col);
    
    // Feasibility check (row, col, 3x3 box)
    bool isFeasible(const SudokuBoard& board, int row, int col, int value) const;
};
