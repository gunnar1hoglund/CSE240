/**

* This program defines a class for a GamePiece object that stores
* a label for the object. It can also truncate or pad the label as needed.

* Completion time: 0.5 hours

*

* @author Gunnar Hoglund

* @version 1.0

*/
package app;

public class GamePiece {

	// instance variable
	private String label;

	public GamePiece() {
		this.label = "---";
	}

	public GamePiece(String newLabel) {
		this.label = newLabel;
	}

	public String getLabel() {
		return label;
	}

	// constructs a string with 3 characters
	public String toString() {

		String NewString = label;

		if (label.length() == 3) {
			NewString = label;
		} else if (label.length() > 3) {
			// getting the first three letters of the
			// string if its too long
			NewString = label.substring(0, 3);
		} else {

			char space = ' ';
			int numSpaces = 3 - label.length();

			// appending spaces to the string if its
			// too short
			for (int i = 0; i < numSpaces; i++) {
				NewString += space;
			}

		}
		return NewString;
	}
}
