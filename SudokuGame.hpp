/******************************************************************************
 *  MODULE NAME  : SudokuGame
 *  FILE         : SudokuGame.hpp
 *  DESCRIPTION  : Header file for the SudokuGame class and custom exceptions.
 *                 Provides interface for running the game loop, handling input,
 *                 and interacting with the Sudoku board.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : April 2025
 ******************************************************************************/

 #pragma once

 /*==============================================================================
  *  INCLUDES
  *============================================================================*/
 #include "SudokuBoard.hpp"
 
 /*==============================================================================
  *  CLASS DEFINITIONS
  *============================================================================*/
 
 /*------------------------------------------------------------------------------
  *  CLASS NAME: SudokuGameException
  *  DESCRIPTION: Base exception class for Sudoku game-specific errors.
  *----------------------------------------------------------------------------*/
 class SudokuGameException : public SudokuBoardException
 {
 public:
     /* Returns a descriptive error message */
     virtual const char* what() const noexcept;
 };
 
 /*------------------------------------------------------------------------------
  *  CLASS NAME: SudokuGameInvalidInputException
  *  DESCRIPTION: Exception class for handling invalid user input in the game.
  *----------------------------------------------------------------------------*/
 class SudokuGameInvalidInputException : public SudokuGameException
 {
 public:
     /* Returns a message for invalid input exception */
     const char* what() const noexcept override;
 };
 
 /*------------------------------------------------------------------------------
  *  CLASS NAME: SudokuGame
  *  DESCRIPTION: Handles the main game loop, user input, and board operations.
  *----------------------------------------------------------------------------*/
 class SudokuGame 
 {
 private:
     SudokuBoard board;   // Sudoku board object
     bool isRunning;      // Game loop control flag
 
 public:
     /* Constructor: Initializes the game */
     SudokuGame();
 
     /* Starts the game loop and handles user interaction */
     void run(void);
 
     /* Displays the main menu to the user */
     void displayMenu(void) const;
 
     /* Prompts the user for a menu choice and returns it */
     int getUserChoice(void) const;
 
     /* Clears any invalid input from the input stream */
     void clearInput(void) const;
 
     /* Prompts the user to press enter to continue */
     char promptContinue(void) const;
 
     /* Handles user's move input and updates the board */
     void handleMove(void);
 
     /* Attempts to solve the current Sudoku board */
     void handleSolve(void); 
 
     /* Exits the game loop and ends the session */
     void handleExit(void);
     
     /* checks if the player won */ 
     bool isGameOver(void) const;
 };
 
 /******************************************************************************
  *  END OF FILE
  ******************************************************************************/
 