/******************************************************************************
 *  MODULE NAME  : Main
 *  FILE         : main.cpp
 *  DESCRIPTION  : Entry point for the Sudoku game application. It initializes
 *                 the game and starts the main loop.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : April 2025
 ******************************************************************************/

/*==============================================================================
 *  INCLUDES
 *============================================================================*/
#include "SudokuGame.hpp"
#include <iostream>

/*==============================================================================
 *  MAIN FUNCTION
 *============================================================================*/

/* Entry point: creates a SudokuGame instance and runs the game loop */
int main(void)
{
    SudokuGame game;

    game.run();

    std::cout << "Thanks for playing." << std::endl;
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
