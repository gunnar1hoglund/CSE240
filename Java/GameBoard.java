public class GameBoard {

	private GamePiece[][] board;

	public GameBoard(int rows, int cols) {
		board = new GamePiece[rows][cols];

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				board[i][j] = new GamePiece();
			}
		}
	}

	private GamePiece getPieceAt(int row, int col) {
		return board[row][col];
	}

	public boolean isSpaceValid(int row, int col) {
		if (row < 0 || row > board.length || col < 0 || col > board[0].length) {
			return false;
		} else
			return true;
	}

	public boolean addPieceAt(int row, int col, GamePiece piece) {
		if (isSpaceValid == false)
			return false;

		if (getPieceAt(row, col) == "---") {
			board[row][col] = piece;
		} else
			return false;
	}

	public boolean movePiece(int srcRow, int srcCol, int destRow, int destCol) {
		GamePiece jenkins = board[srcRow][srcCol];

		if (addPieceAt(destRow, destCol, jenkins)) {
			board[srcRow][srcCol] = "---";
			return true;
		} else
			return false;

	}

	public String toString() {

		String gameBoard = "The Game Board\n" + "--------------------";

		System.out.println();
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[0].length; j++) {
				gameBoard += board[i][j];
			}
			gameBoard += "\n";
			;
		}
		return gameBoard;
	}
}
