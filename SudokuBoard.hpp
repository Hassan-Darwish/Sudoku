#pragma once
#include <vector>

class SudokuBoardException
{
public:
    virtual const char* what() const noexcept;
};
class SudokuBoardOutOfBoundsException : public SudokuBoardException
{
public:
    const char* what() const noexcept override;
};
class SudokuBoardGameRuleException : public SudokuBoardException
{
public:
    const char* what() const noexcept override;
};
class SudokuBoardValueOutOfBoundsException : public SudokuBoardException
{
public:
    const char* what() const noexcept override;
};

class SudokuBoard
{
private:
    std::vector<std::vector<int>> board;
public:
    /*
    *  Description: SudokuBoard class constructor which initialize the board values
    */
    SudokuBoard();

    /*
    *  Description: prints the 9x9 sudoku board
    */
    void printBoard(void) const;

    /*
    *  Description: checks if the move is in bounds to make or not ie (1-9)
    */
    bool isInBound(int row, int col) const;
    bool isValueInBound(int row, int col, int value) const;
    

    /*
    *  Description: used to manipulate the value of the current cell
    */
    void setCell(int row, int col, int value);

    /*
    *  Description: used to track the value of the current cell
    */
    int getCell(int row, int col) const;

    /*
    *  Description: checks if cell is empty or not
    */
    bool isCellEmpty(int row, int col) const;

    /*
    *  Description: checks if the move is legal to make or not
    */
    bool isGameRuleValid(int row, int col, int value) const;

};