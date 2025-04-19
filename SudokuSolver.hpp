/******************************************************************************
 *  MODULE NAME  : SudokuSolver
 *  FILE         : SudokuSolver.hpp
 *  DESCRIPTION  : Header file for the SudokuSolver class that provides a
 *                 backtracking algorithm to solve a Sudoku board.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : April 2025
 ******************************************************************************/

 #pragma once

 /*==============================================================================
  *  INCLUDES
  *============================================================================*/
 #include "SudokuBoard.hpp"
 #include <vector>
 
 /*==============================================================================
  *  CLASS DEFINITIONS
  *============================================================================*/
 
 /*------------------------------------------------------------------------------
  *  CLASS NAME: SudokuSolver
  *  DESCRIPTION: Implements a backtracking solver for Sudoku puzzles.
  *----------------------------------------------------------------------------*/
 class SudokuSolver {
 public:
     /* Solves the provided Sudoku board using backtracking */
     bool solve(SudokuBoard& board);
 
 private:
     /* Recursive helper function to solve the board from a given cell */
     bool solveSudokuRec(std::vector<std::vector<int>>& mat, int row, int col);
 
     /* Checks if placing a number at (row, col) is valid */
     bool isSafe(const std::vector<std::vector<int>>& mat, int row, int col, int num);
 };
 
 /******************************************************************************
  *  END OF FILE
  ******************************************************************************/
 