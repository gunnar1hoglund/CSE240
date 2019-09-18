/*
 * This is the header implementation for the gameboard class
 *
 * Completion time: 5 minutes
 *
 * @author Gunnar Hoglund
 * @version 1.0
 */
#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "gamepiece.h"

class GameBoard
{
    private:
        GamePiece **board;
        int rows, columns;
        bool spacey(int row, int col);


    public:
        GameBoard();
        GameBoard(int rows, int cols);
        bool isSpaceValid(int row, int col);
        bool addPiece(GamePiece piece, int row, int col);
        bool movePiece(int srcRow, int srcCol, int destRow, int destCol);
        void print();
};

#endif

