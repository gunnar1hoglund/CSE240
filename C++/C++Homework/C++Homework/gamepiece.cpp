/*
 * This is program implements the gamepiece class
 * it contains a label for the gamepiece and
 * other necessary class member functions
 *
 * Completion time: 1 hour
 *
 * @author Gunnar Hoglund
 * @version 1.0
 */
#include <iostream>
#include "gamepiece.h"

// assign the default string to the
// game pieces label
GamePiece::GamePiece(void)
{
    strcpy(label, "---");
}

// overloaded constructor
GamePiece::GamePiece(char* newLabel)
{
    strcpy(label, newLabel);
}

// getter function for the label attribute
char* GamePiece::getLabel()
{
    return label;
}

// trims or pads the label as needed
char* GamePiece::toString()
{
    // get the length of the string
    int i = 0; // length of the c string
    while( label[i] != '\0')
    {
        i++;
    }
    
    // padding or trimming string as needed
    if (i == 3)
    {
        return label;
    }
    else if (i > 3)
    {
        char label_temp[4];
        
        // storing the first three characterts
        strncpy(label_temp, label, 3);
        label_temp[3] = '\0'; // manually adding the null character
        
        strcpy(label, label_temp);
        
        return label;
    }
    else
    {
        // if i < 3 loop through and add however many
        // spaces to the end of the string
        int diff = 3 - i;
        
        // adding however many spaces needed
        for (int j = 1; j <= diff; j++) {
            label[i] = ' ';
        }
        
        label[3] = '\0'; // manually adding the null character
        
        return label;
    }

}
