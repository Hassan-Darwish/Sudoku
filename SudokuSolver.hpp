#pragma once
#include "SudokuBoard.hpp"
#include <vector>

class SudokuSolver {
public:
    bool solve(SudokuBoard& board);

private:
    bool solveSudokuRec(std::vector<std::vector<int>>& mat, int row, int col);
    bool isSafe(const std::vector<std::vector<int>>& mat, int row, int col, int num);
};
