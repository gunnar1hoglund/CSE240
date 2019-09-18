public class GamePiece {

	// instance variable
	String label;

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
		
		if(label.length() == 3){
			NewString = label;
		}
		else if (label.length() > 3){
			NewString = label.substring(0,2);
		}
		else{
			char space = ' ';
			int numSpaces = 3 - label.length();
			
			for(int i = 0; i < numSpaces; i++){
				NewString += space;
			}	
		
		}
		return NewString;	
	}
}
