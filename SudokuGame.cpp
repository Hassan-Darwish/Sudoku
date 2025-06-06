/******************************************************************************
 *  MODULE NAME  : SudokuGame
 *  FILE         : SudokuGame.cpp
 *  DESCRIPTION  : Source file implementing the SudokuGame class methods and
 *                 exception definitions for handling game operations and input.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : April 2025
 ******************************************************************************/

/*==============================================================================
 *  INCLUDES
 *============================================================================*/
#include "SudokuGame.hpp"
#include "SudokuSolver.hpp"
#include <iostream>
#include <limits>

/*==============================================================================
 *  EXCEPTION DEFINITIONS
 *============================================================================*/

/* Returns generic game error message */
const char* SudokuGameException::what() const noexcept
{
    return "General Game Exception.";
}

/* Returns specific error message for invalid input */
const char* SudokuGameInvalidInputException::what() const noexcept
{
    return "Invalid User Input Exception.";
}

/*==============================================================================
 *  CONSTRUCTOR
 *============================================================================*/

/* Initializes the SudokuGame with the running flag set to true */
SudokuGame::SudokuGame() : isRunning(true) {}

/*==============================================================================
 *  PUBLIC FUNCTION DEFINITIONS
 *============================================================================*/

/* Main game loop: handles menu display, user choice, and dispatch */
void SudokuGame::run(void)
{
    while(isRunning)
    {
        board.printBoard();
        SudokuGame::displayMenu();

        int userChoice;
        try
        {
            userChoice = SudokuGame::getUserChoice();
        }
        catch(SudokuGameException& GameError)
        {
            std::cerr << GameError.what() << std::endl;
            SudokuGame::clearInput();
            SudokuGame::promptContinue();
        }
        switch(userChoice)
        {
            case 1:
            SudokuGame::handleMove();
            break;

            case 2:
            SudokuGame::handleSolve();
            break;
            
            case 3:
            SudokuGame::handleExit();
            break;

            default:
            break;
        }
    }
    if(SudokuGame::isGameOver())
    {
        SudokuGame::handleExit();
    }
}

/* Displays the main game menu options */
void SudokuGame::displayMenu(void) const
{
    std::cout 
    << "1) Enter a move\n"
    << "2) Solve automatically\n"
    << "3) Exit\n"
    << std::endl;
}

/* Reads and returns user menu choice, throws on invalid input */
int SudokuGame::getUserChoice(void) const
{
    int userChoice;

    std::cin >> userChoice;
    if (std::cin.fail()) {throw SudokuGameInvalidInputException();}
    return userChoice;
}

/* Clears the input stream of invalid entries */
void SudokuGame::clearInput(void) const
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush leftovers
}

/* Prompts the user to press Enter to continue */
char SudokuGame::promptContinue(void) const
{
    SudokuGame::clearInput();
    std::cout << "\nPress Enter to continue... or q to quit :";
    return std::cin.get(); // wait for Enter 
}

/* Reads and validates a user's move, applies it to the board */
void SudokuGame::handleMove(void)
{
    int row, col, value;

    std::cout << "Enter row (1-9), column (1-9), and value (1-9): ";

    while(true)
    {
        try 
        {
            std::cin >> row;
            if(std::cin.fail())
            {
                throw SudokuGameInvalidInputException();
            }
            std::cin >> col;
            if(std::cin.fail())
            {
                throw SudokuGameInvalidInputException();
            }
            std::cin >> value;
            if(std::cin.fail())
            {
                throw SudokuGameInvalidInputException();
            }

                board.setCell(row,col,value);
            }
        catch(const SudokuBoardException& boardError)
        {
            std::cerr << boardError.what() << std::endl;

            if(SudokuGame::promptContinue() == 'q')
            {
                break;
            }
            board.printBoard();
            std::cout << "\nEnter row (1-9), column (1-9), and value (1-9): ";
        }
    }
}

/* Attempts to automatically solve the Sudoku puzzle */
void SudokuGame::handleSolve(void)
{
    SudokuSolver solver;
    try {
        if (solver.solve(board)) {
            std::cout << "Puzzle solved successfully!\n";
        } else {
            std::cout << "This puzzle cannot be solved.\n";
        }
    } catch (const SudokuBoardException& e) {
        std::cout << "Solver Error: " << e.what() << std::endl;
    } 
    board.printBoard();
    SudokuGame::handleExit();
}

/* Exits the game loop */
void SudokuGame::handleExit(void)
{
    isRunning = false;
}

/* 
 * checks if the player won 
 */
bool SudokuGame::isGameOver(void) const
{
    for (int outerLoopIndex = 1; outerLoopIndex <= 9; outerLoopIndex++)
    {
        for (int innerLoopIndex = 1; innerLoopIndex <= 9; innerLoopIndex++)
        {
            if(board.getCell(outerLoopIndex,innerLoopIndex) == 0)
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
