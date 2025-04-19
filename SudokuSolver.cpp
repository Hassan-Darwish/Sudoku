#include "SudokuSolver.hpp"
#include <cmath>

bool SudokuSolver::solve(SudokuBoard& board) {
    return solveRecursive(board, 0, 0);
}

bool SudokuSolver::solveRecursive(SudokuBoard& board, int row, int col) {
    const int N = 9;

    if (row == N) return true;

    if (board.getCell(row, col) != 0) {
        if (col == N - 1) return solveRecursive(board, row + 1, 0);
        else return solveRecursive(board, row, col + 1);
    }

    for (int val = 1; val <= 9; val++) {
        if (isFeasible(board, row, col, val)) {
            board.setCell(row, col, val);
            if (col == N - 1) {
                if (solveRecursive(board, row + 1, 0)) return true;
            } else {
                if (solveRecursive(board, row, col + 1)) return true;
            }
            board.setCell(row, col, 0); // Backtrack
        }
    }

    return false;
}

bool SudokuSolver::isFeasible(const SudokuBoard& board, int row, int col, int value) const {
    int boxRow = (row / 3) * 3;
    int boxCol = (col / 3) * 3;

    // Row
    for (int i = 0; i < 9; ++i)
        if (board.getCell(row, i) == value) return false;

    // Column
    for (int i = 0; i < 9; ++i)
        if (board.getCell(i, col) == value) return false;

    // 3x3 box
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board.getCell(boxRow + i, boxCol + j) == value) return false;

    return true;
}
