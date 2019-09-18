/*
 * Main function for the program
 *
 * Completion time: 10 minutes
 *
 * @author Gunnar Hoglund
 * @version 1.0
 */
#include "gameboard.h"
#include "gamepiece.h"

#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    /* declare local variables */
    int row;
    int col;
    int destRow;
    int destCol;
    int rowNum;
    int colNum;
    char inputString[30];

    /* get the size of the game board */
    cout << "Please enter the number of rows.\n";
    cin >> rowNum;

    cout << "Please enter the number of columns.\n";
    cin >> colNum;

    GameBoard board(rowNum, colNum);

    /* get the first piece's label */
    cout << "Please enter a label for a new piece. Enter \"Q\" when done.\n";
    cin >> inputString;

    while (strcmp(inputString, "Q") != 0 && strcmp(inputString, "q") != 0)
    {
        GamePiece piece(inputString);

        /* get the location to place the piece */
        cout << "Please enter a row for the piece.\n";
        cin >> row;

        cout << "Please enter a column for the piece.\n";
        cin >> col;

        /* verify the space is valid then add the piece to the board */
        if (board.isSpaceValid(row, col))
        {
            if (board.addPiece(piece, row, col))
            {
                cout << "New piece \"" << piece.getLabel() << "\" added.\n";
            }
            else
            {
                cout << "A piece is already at that space.\n";
            }
        }
        else
        {
            cout << "Invalid row and/or column.\n";
        }

        /* get the label for the next piece */
        cout << "Please enter a label for a new piece. Enter \"Q\" when done.\n";
        cin >> inputString;
    }

    /* print the board and check if user wants to move a piece */
    board.print();
    cout << "Would you like to move a piece? Enter \"Y\" to move a piece.\n";
    cin >> inputString;

    while (strcmp(inputString, "Y") == 0 || strcmp(inputString, "y") == 0)
    {
        /* get the location of the piece */
        cout << "Please enter the piece's row.\n";
        cin >> row;

        cout << "Please enter the piece's column.\n";
        cin >> col;

        /* get the destination for the piece */
        cout << "Please enter the piece's new row.\n";
        cin >> destRow;

        cout << "Please enter the piece's new column.\n";
        cin >> destCol;

        /* verify both spaces are valid then move the piece */
        if (board.isSpaceValid(row, col) &&
            board.isSpaceValid(destRow, destCol))
        {
            if (board.movePiece(row, col, destRow, destCol))
            {
                cout << "Piece moved to new space.\n";
            }
            else
            {
                cout << "A piece is already in that space.\n";
            }
        }
        else
        {
            cout << "A row or column is invalid. No piece moved.\n";
        }

        /* print the board and check if the user wants move another piece */
        board.print();
        cout << "Would you like to move a piece? Enter \"Y\" to move a piece.\n";
        cin >> inputString;
    }

    return 0;
}
