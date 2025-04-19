/******************************************************************************
 *  MODULE NAME  : Sudoku Board
 *  FILE         : SudokuBoard.hpp
 *  DESCRIPTION  : This file defines the SudokuBoard class, which represents
 *                 the 9x9 Sudoku board, along with custom exceptions for board
 *                 validation and manipulation.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : April 2025
 ******************************************************************************/

 #pragma once
 #include <vector>
 
 /*==============================================================================
  *  EXCEPTION CLASS DEFINITIONS
  *============================================================================*/
 
 /*
  * Base exception class for all Sudoku board-related exceptions
  */
 class SudokuBoardException
 {
 public:
     /*
      *  Description: Returns the error message associated with the exception
      */
     virtual const char* what() const noexcept;
 };
 
 /*
  * Exception thrown when an out-of-bounds move is made (row or column out of range)
  */
 class SudokuBoardOutOfBoundsException : public SudokuBoardException
 {
 public:
     /*
      *  Description: Returns the error message for out-of-bounds exception
      */
     const char* what() const noexcept override;
 };
 
 /*
  * Exception thrown when a move violates Sudoku game rules (repeated value in row/column/subgrid)
  */
 class SudokuBoardGameRuleException : public SudokuBoardException
 {
 public:
     /*
      *  Description: Returns the error message for game rule violation exception
      */
     const char* what() const noexcept override;
 };
 
 /*
  * Exception thrown when an invalid value (not between 1 and 9) is attempted to be inserted
  */
 class SudokuBoardValueOutOfBoundsException : public SudokuBoardException
 {
 public:
     /*
      *  Description: Returns the error message for value out of bounds exception
      */
     const char* what() const noexcept override;
 };
 
 /*
  * Exception thrown when attempting to place a value in a non-empty cell
  */
 class SudokuBoardNotEmptyBlockException : public SudokuBoardException
 {
 public:
     /*
      *  Description: Returns the error message for block not empty exception
      */
     const char* what() const noexcept override;
 };
 
 /*==============================================================================
  *  MAIN CLASS: SudokuBoard
  *============================================================================*/
 
 /*
  * SudokuBoard class represents a 9x9 Sudoku board and provides methods for
  * board manipulation, validation, and game rule checking.
  */
 class SudokuBoard
 {
 private:
     std::vector<std::vector<int>> board;  // 9x9 Sudoku board matrix
 
 public:
     /*
      *  Constructor: Initializes the Sudoku board with a preset puzzle
      */
     SudokuBoard();
 
     /*
      *  Description: Prints the current 9x9 Sudoku board to the console
      */
     void printBoard(void) const;
 
     /*
      *  Description: Validates if the given row and column are within the 1-9 bounds
      */
     bool isInBound(int row, int col) const;
 
     /*
      *  Description: Validates if the given value is within 1-9 bounds and
      *               ensures the cell is empty
      */
     bool isValueInBound(int row, int col, int value) const;
 
     /*
      *  Description: Sets the value at the specified cell (row, col) if valid
      */
     void setCell(int row, int col, int value);
 
     /*
      *  Description: Retrieves the value of the specified cell (row, col)
      */
     int getCell(int row, int col) const;
 
     /*
      *  Description: Checks if the specified cell (row, col) is empty (contains 0)
      */
     bool isCellEmpty(int row, int col) const;
 
     /*
      *  Description: Validates if placing the value at (row, col) is allowed by Sudoku rules
      */
     bool isGameRuleValid(int row, int col, int value) const;
 
     /*
      *  Description: Returns the current 9x9 board as a matrix (vector of vectors)
      */
     std::vector<std::vector<int>> getMatrix() const;
 
     /*
      *  Description: Sets the board to the provided matrix
      */
     void setMatrix(const std::vector<std::vector<int>>& mat);
 };
 
 /******************************************************************************
  *  END OF FILE
  ******************************************************************************/
 