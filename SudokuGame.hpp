#pragma once
#include "SudokuBoard.hpp"

class SudokuGameException
{
public:
    virtual const char* what() const noexcept;
};
class SudokuGameInvalidInputException : public SudokuGameException
{
public:
    const char* what() const noexcept override;
};
class SudokuGame 
{
private:
    SudokuBoard board;
    bool isRunning;

public:
    SudokuGame();

    void run(void);
    void displayMenu(void) const;
    int getUserChoice(void) const;
    void clearInput(void) const;
    void promptContinue(void) const;

    void handleMove(void);
    void handleSolve(void); 
    void handleExit(void);
};
