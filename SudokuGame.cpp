#include "SudokuGame.hpp"
#include "SudokuSolver.hpp"
#include <iostream>
#include <limits>

const char* SudokuGameException::what() const noexcept
{
    return "General Game Exception.";
}
const char* SudokuGameInvalidInputException::what() const noexcept
{
    return "Invalid User Input Exception.";
}

SudokuGame::SudokuGame() : isRunning(true) {}

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
}
void SudokuGame::displayMenu(void) const
{
    std::cout 
    << "1) Enter a move\n"
    << "2) Solve automatically\n"
    << "3) Exit\n"
    << std::endl;
}
int SudokuGame::getUserChoice(void) const
{
    int userChoice;

    std::cin >> userChoice;
    if (std::cin.fail()) {throw SudokuGameInvalidInputException();}
    return userChoice;
}
void SudokuGame::clearInput(void) const
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void SudokuGame::promptContinue(void) const
{
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush leftovers
    std::cin.get(); // wait for Enter 
}

void SudokuGame::handleMove(void)
{
    int row, col, value;

    std::cout << "Enter row (1-9), column (1-9), and value (1-9): ";
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
    try 
    {
        board.setCell(row,col,value);
    }
    catch(const SudokuBoardException& boardError)
    {
        std::cerr << boardError.what() << std::endl;
        SudokuGame::promptContinue();
        SudokuGame::handleMove();
    }
}
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
    SudokuGame::handleExit();
}
void SudokuGame::handleExit(void)
{
    isRunning = false;
}