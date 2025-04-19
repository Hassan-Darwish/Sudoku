#include "SudokuBoard.hpp"
#include <iostream>
#include <exception>

const char* SudokuBoardException::what() const noexcept
{
    return "Invalid Board Exception.";
}
const char* SudokuBoardOutOfBoundsException::what() const noexcept 
{
    return "Invalid Move (Out of Bounds Exception).";
}
const char* SudokuBoardGameRuleException::what() const noexcept
{
    return "Invalid Move (Game Rule Exception).";
}
const char* SudokuBoardValueOutOfBoundsException::what() const noexcept
{
    return "Invalid Move (Value Out of Bounds Exception).";
}

/*
*  Description: SudokuBoard class constructor which initialize the board values
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
*  Description: prints the 9x9 sudoku board values
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
            if(board[outerLoopIndex][innerLoopIndex])// print number if not equal 0
            {
                std::cout << board[outerLoopIndex][innerLoopIndex] << " ";
            }
            else
            {
                std::cout << "." << " "; // if equal 0 replace with dot
            }
            if((innerLoopIndex + 1) % 3 == 0)
            {
                std:: cout << " |";
            }
        }
        
    }
}

/*
*  Description: checks if the move is in bounds to make or not ie (1-9)
*/
bool SudokuBoard::isInBound(int row, int col) const
{
    if( row > 9 || row < 1 || 
        col > 9 || col < 1)
   {
       throw SudokuBoardOutOfBoundsException();
       return false;
   }
   else
   {
       return true;
   }
}
bool SudokuBoard::isValueInBound(int row, int col, int value) const
{
    
    if(value > 9 || value < 1 || 
       !(SudokuBoard::isInBound(row, col)) ||
       !(SudokuBoard::isCellEmpty(row, col)))
    {
        throw SudokuBoardValueOutOfBoundsException();
        return false;
    }
}

/*
*  Description: used to manipulate the value of the current cell
*/
void SudokuBoard::setCell(int row, int col, int value)
{
    if(SudokuBoard::isValueInBound(row, col, value))
    {
        board[row][col] = value;
    }
}

/*
*  Description: used to track the value of the current cell
*/
int SudokuBoard::getCell(int row, int col) const
{
    if(SudokuBoard::isInBound(row, col))
    {
        return board[row][col];
    }
}

/*
*  Description: checks if cell is empty or not
*/
bool SudokuBoard::isCellEmpty(int row, int col) const
{
    if(board[row][col])
    {
        return false;
    }
    else
    {
        return true;
    }
}

/*
*  Description: checks if the move is legal to make or not
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
        if (board[rowLoopIndex][col] == value)
        {
            throw SudokuBoardGameRuleException();
        }
    }

    // Check row
    for (int colLoopIndex = 0; colLoopIndex < board.size(); colLoopIndex++)
    {
        if (board[row][colLoopIndex] == value)
        {
            throw SudokuBoardGameRuleException();
        }
    }

    return true;
}

