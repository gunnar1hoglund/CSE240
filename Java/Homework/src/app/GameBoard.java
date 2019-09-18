/**

* This program defines a class for a Gameboard. It instantiates a board of
  a given size and fills it with GamePiece objects

* Completion time: 1 hour

*

* @author Gunnar Hoglund

* @version 1.0

*/
package app;

public class GameBoard {

	private GamePiece[][] board;

	// constructs a gameboard filled with gamepiece objects
	public GameBoard(int rows, int cols) {
		board = new GamePiece[rows][cols];

		// instantiating each gamePiece object
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				board[i][j] = new GamePiece();
			}
		}
	}

	// returns the gamePiece at a specified array index
	private GamePiece getPieceAt(int row, int col) {
		return board[row][col];
	}

	// checks if a space is within the bounds of the game board
	public boolean isSpaceValid(int row, int col) {
		if (row < 0 || row > board.length || col < 0 || col > board[0].length) {
			return false;
		} else
			return true;
	}

	// adds a piece to the gameboard
	public boolean addPieceAt(int row, int col, GamePiece piece) {
		GamePiece jenkins = getPieceAt(row, col);

		if (jenkins.getLabel() == "---") {
			board[row][col] = piece;
			return true;
		} else
			return false;
	}

	// moves a piece from one space to another given there is not
	// already a piece there
	public boolean movePiece(int srcRow, int srcCol, int destRow, int destCol) {
		// temp storage for GamePiece object
		GamePiece jenkins = board[srcRow][srcCol];
		// empty GamePiece object to asign to the old object
		GamePiece newJenkins = new GamePiece();

		if (getPieceAt(destRow, destCol).getLabel() == "---") {
			board[destRow][destCol] = jenkins;
			board[srcRow][srcCol] = newJenkins;
			return true;
		} else
			return false;
	}

	// formats and prints the gameBoard to the terminal
	public String toString() {

		String gameBoard = "The Game Board\n" + "--------------------\n";

		System.out.println();
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[0].length; j++) {
				gameBoard += board[i][j].toString() + ' ';
			}
			gameBoard += "\n";
		}
		return gameBoard;
	}
}
