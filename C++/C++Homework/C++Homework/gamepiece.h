/*
 * This is the header implementation for the gamepiece class
 *
 * Completion time: 5 minutes
 *
 * @author Gunnar Hoglund
 * @version 1.0
 */
#ifndef GAMEPIECE_H
#define GAMEPIECE_H

class GamePiece
{
    private:
        char label[30];
    
    public:
        GamePiece();
        GamePiece(char* newLabel);
        char* getLabel();
        char* toString();
    
};

#endif
