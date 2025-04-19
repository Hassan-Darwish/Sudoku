/******************************************************************************
 *  MODULE NAME  : Sudoku Board
 *  FILE         : SudokuBoard.cpp
 *  DESCRIPTION  : This file implements the SudokuBoard class which handles
 *                 board representation, validation, and manipulation. It also
 *                 defines board-related exceptions.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : April 2025
 ******************************************************************************/

/*==============================================================================
 *  INCLUDES
 *============================================================================*/
#include "SudokuBoard.hpp"
#include <iostream>
#include <exception>

/*==============================================================================
 *  EXCEPTION DEFINITIONS
 *============================================================================*/

/* General board exception message */
const char* SudokuBoardException::what() const noexcept
{
    return "Invalid Board Exception.";
}

/* Thrown when cell position is outside 1-9 range */
const char* SudokuBoardOutOfBoundsException::what() const noexcept 
{
    return "Invalid Move (Out of Bounds Exception).";
}

/* Thrown when move violates Sudoku rules */
const char* SudokuBoardGameRuleException::what() const noexcept
{
    return "Invalid Move (Game Rule Exception).";
}

/* Thrown when inserted value is outside allowed range */
const char* SudokuBoardValueOutOfBoundsException::what() const noexcept
{
    return "Invalid Move (Value Out of Bounds Exception).";
}

/* Thrown when trying to overwrite a non-empty cell */
const char* SudokuBoardNotEmptyBlockException::what() const noexcept
{
    return "Invalid Move (Block Not Empty Exception).";
}

/*==============================================================================
 *  FUNCTION DEFINITIONS
 *============================================================================*/

/*
 * Constructor: Initializes the Sudoku board with a preset puzzle
 */
SudokuBoard::SudokuBoard()
{
    board = {
        {5,3,0, 0,7,0, 0,0,0},
        {6,0,0, 1,9,5, 0,0,0},
        {0,9,8, 0,0,0, 0,6,0},
        
        {8,0,0, 0,6,0, 0,0,3},
        {4,0,0, 8,0,3, 0,0,1},
        {7,0,0, 0,2,0, 0,0,6},
        
        {0,6,0, 0,0,0, 2,8,0},
        {0,0,0, 4,1,9, 0,0,5},
        {0,0,0, 0,8,0, 0,7,9}
    };
}

/*
 * Prints the Sudoku board to the console
 */
void SudokuBoard::printBoard(void) const
{
    for(int outerLoopIndex = 0; outerLoopIndex < board.size(); outerLoopIndex++)
    {
        if(outerLoopIndex % 3 == 0)
        {
            std::cout << std::endl << "-------------------------------------" << std::endl;
        }
        else
        {
            std::cout << std::endl;
        }

        for(int innerLoopIndex = 0; innerLoopIndex < board[outerLoopIndex].size(); innerLoopIndex++)
        {
            if(board[outerLoopIndex][innerLoopIndex])
            {
                std::cout << board[outerLoopIndex][innerLoopIndex] << " ";
            }
            else
            {
                std::cout << "." << " ";
            }
            if((innerLoopIndex + 1) % 3 == 0)
            {
                std:: cout << " |";
            }
        } 
    }
    std::cout << std::endl;
}

/*
 * Validates if row and column are within [1-9] bounds
 */
bool SudokuBoard::isInBound(int row, int col) const
{
    if( row > 9 || row < 1 || 
        col > 9 || col < 1)
   {
       throw SudokuBoardOutOfBoundsException();
   }
   return true;
}

/*
 * Validates if value and cell coordinates are within bounds and cell is empty
 */
bool SudokuBoard::isValueInBound(int row, int col, int value) const
{
    if(value > 9 || value < 1 || 
       !(SudokuBoard::isInBound(row, col)) ||
       !(SudokuBoard::isCellEmpty(row, col)))
    {
        throw SudokuBoardValueOutOfBoundsException();
    }
    return true;
}

/*
 * Attempts to place a value in the specified cell after validations
 */
void SudokuBoard::setCell(int row, int col, int value)
{
    if(SudokuBoard::isValueInBound(row, col, value) && SudokuBoard::isGameRuleValid(row, col, value))
    {
        board[row-1][col-1] = value;
    }
}

/*
 * Retrieves the value at a specific board cell
 */
int SudokuBoard::getCell(int row, int col) const
{
    if(SudokuBoard::isInBound(row, col))
    {
        return board[row-1][col-1];
    }
    return -1;
}

/*
 * Checks whether a cell is empty (contains 0)
 */
bool SudokuBoard::isCellEmpty(int row, int col) const
{
    if(board[row-1][col-1])
    {
        throw SudokuBoardNotEmptyBlockException();
    }
    return true;
}

/*
 * Ensures that placing a value does not violate Sudoku rules
 */
bool SudokuBoard::isGameRuleValid(int row, int col, int value) const
{
    SudokuBoard::isValueInBound(row, col, value);

    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    // Check 3x3 subgrid
    for (int outerLoopIndex = 0; outerLoopIndex < 3; outerLoopIndex++)
    {
        for (int innerLoopIndex = 0; innerLoopIndex < 3; innerLoopIndex++)
        {
            if (board[startRow + outerLoopIndex][startCol + innerLoopIndex] == value)
            {
                throw SudokuBoardGameRuleException();
            }
        }
    }

    // Check column
    for (int rowLoopIndex = 0; rowLoopIndex < board.size(); rowLoopIndex++)
    {
        if (board[rowLoopIndex][col-1] == value)
        {
            throw SudokuBoardGameRuleException();
        }
    }

    // Check row
    for (int colLoopIndex = 0; colLoopIndex < board.size(); colLoopIndex++)
    {
        if (board[row-1][colLoopIndex] == value)
        {
            throw SudokuBoardGameRuleException();
        }
    }

    return true;
}

/*
 * Returns the full board matrix
 */
std::vector<std::vector<int>> SudokuBoard::getMatrix() const {
    return board;
}

/*
 * Sets the full board matrix (used by solver)
 */
void SudokuBoard::setMatrix(const std::vector<std::vector<int>>& mat) {
    board = mat;
}
/* 
 * checks if the player won 
 */
bool SudokuBoard::isGameOver(void) const
{
    for (int outerLoopIndex = 0; outerLoopIndex < board.size(); outerLoopIndex++)
    {
        for (int innerLoopIndex = 0; innerLoopIndex < board[outerLoopIndex].size(); innerLoopIndex++)
        {
            if(board[outerLoopIndex][innerLoopIndex] == 0)
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
