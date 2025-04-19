/******************************************************************************
 *  MODULE NAME  : SudokuSolver
 *  FILE         : SudokuSolver.cpp
 *  DESCRIPTION  : Implements the backtracking algorithm for solving Sudoku
 *                 puzzles using the SudokuSolver class.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : April 2025
 ******************************************************************************/

/*==============================================================================
 *  INCLUDES
 *============================================================================*/
#include "SudokuSolver.hpp"

/*==============================================================================
 *  PUBLIC FUNCTION DEFINITIONS
 *============================================================================*/

/* Attempts to solve the given Sudoku board using backtracking */
bool SudokuSolver::solve(SudokuBoard& board) 
{
    std::vector<std::vector<int>> mat = board.getMatrix(); // new method below
    bool solved = solveSudokuRec(mat, 0, 0);

    if (solved) 
    {
        board.setMatrix(mat); // new method below
    }

    return solved;
}

/*==============================================================================
 *  PRIVATE FUNCTION DEFINITIONS
 *============================================================================*/

/* Recursively solves the board using backtracking starting from (row, col) */
bool SudokuSolver::solveSudokuRec(std::vector<std::vector<int>>& mat, int row, int col) 
{
    int n = mat.size();

    if (row == n - 1 && col == n)
    {
        return true;
    }
    if (col == n) 
    {
        row++;
        col = 0;
    }

    if (mat[row][col] != 0)
    {
        return solveSudokuRec(mat, row, col + 1);
    }
    for (int num = 1; num <= n; num++) 
    {
        if (isSafe(mat, row, col, num)) 
        {
            mat[row][col] = num;

            if (solveSudokuRec(mat, row, col + 1))
            {
                return true;
            }
            mat[row][col] = 0;
        }
    }

    return false;
}

/* Checks if it's safe to place 'num' at position (row, col) in the board */
bool SudokuSolver::isSafe(const std::vector<std::vector<int>>& mat, int row, int col, int num) 
{
    for (int x = 0; x < 9; x++) 
    {
        if (mat[row][x] == num || mat[x][col] == num)
            return false;
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (mat[startRow + i][startCol + j] == num)
            {
                return false;
            }
        }
    }
    return true;
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
