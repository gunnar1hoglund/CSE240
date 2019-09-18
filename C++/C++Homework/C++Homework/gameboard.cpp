/*
 * This program implements the gameboard class
 * it contains a 2d array that acts as the gameboard
 * as well as the logic to add gamepiece objects to the board
 * and move them around
 *
 * Completion time: 2 hours
 *
 * @author Gunnar Hoglund
 * @version 1.0
 */
#include "gameboard.h"
#include <iostream>
#include <stdio.h>

// declares a 2d array of gamepiece objects
// based on the rows and col variables
GameBoard::GameBoard(int rows, int cols)
{
    
    board = new GamePiece*[rows]; // delcaring an array of the size
                                  // the rows variable

    // adding an array of length cols
    // to each cell of the rows array
    for (int i = 0; i < rows; ++i) {
        board[i] = new GamePiece[cols];
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0 ; j < cols; j++) {
            board[i][j] = GamePiece();
        }
    }

    this->columns = cols;
    this->rows = rows;
}

// checks if a space falls within the bounds
// of the array
bool GameBoard::isSpaceValid(int row, int col)
{
    if (row < 0 || col < 0)
    {
        return false;
    }
    else if(row >= this->rows || col >= this->columns)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// helper function checks if a space has a piece in it
// returns true if its empty or false if it is not
bool GameBoard::spacey(int row, int col)
{
    char default_label[] = "---";
    char new_str[4];
    int j;
    strncpy(new_str, board[row][col].getLabel(), 3);
    new_str[3] = '\0';
    
    j = strcmp (new_str, default_label);
    
    if (j == 0) {
        return true;
    }
    else
    {
        return false;
    }
}

// checks if a space is empty and adds a piece to it
// otherwise it returns false
bool GameBoard::addPiece(GamePiece piece, int row, int col)
{
    bool j = spacey(row, col);
    
    //
    if (j) {
        board[row][col] = piece;
        return true;
    }
    else
    {
        return false;
    }
}

// moves a piece from one part of the board to the other
bool GameBoard::movePiece(int srcRow, int srcCol, int destRow, int destCol)
{
    bool src = spacey(srcRow, srcCol);
    bool dest = spacey(destRow, destCol);
    char temp[4];
    
    strncpy(temp, board[srcRow][srcCol].getLabel(), 3);
    temp[3] = '\0';
    
    // if the destination is empty and the source
    // is occupied move the piece
    if (src == false && dest == true)
    {
        board[destRow][destCol] = GamePiece(temp); // set the destination
        board[srcRow][srcCol] = GamePiece(); // reset the source
        return true;
    }
    else
    {
        return false;
    }
}

void GameBoard::print()
{
    for(int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->columns; j++) {
            std::cout << this->board[i][j].toString() << " ";
        }
        std::cout << std::endl;
    }
    
}
