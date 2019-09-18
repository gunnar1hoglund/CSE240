/*
 * This program implements a gameboard and a gamepiece type
 * it displays that to the console and allows you to
 * add pieces and move them around
 *
 * Completion time: 4 hours
 *
 * @author Gunnar Hoglund
 * @version 1.0
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct game_piece
{
    char label[30];
};

// creating 2d array of game_pieces
struct game_board
{
    struct game_piece **board;
    int rows;
    int cols;
};

// setting to default value
void game_piece_init_default(struct game_piece* piece)
{
    strcpy(piece->label, "---");
}

// setting to passed in value
void game_piece_init(struct game_piece* piece, char* new_label)
{
    strcpy(piece->label, new_label);
}

// getting for game_piece label
char* game_piece_get_label(struct game_piece* piece)
{
    return piece->label;
}

// trims or pads string as needed
char* game_piece_to_string(struct game_piece* piece)
{
    int i = 0;
    char * new_str1 = (char *) malloc(4);
    
    strncpy(new_str1, piece->label, 3);
    
    new_str1[3] = '\0';
    
    
    // calculates the length of the string
    while(new_str1[i] != '\0')
    {
        i++;
    }
    
    if(i == 3)
    {
        return new_str1;
    }
    else
    {
        int diff = 3 - i;
        
        for(int j = 1; j <= diff; j++)
        {
            new_str1[j] = ' ';
        }
        return new_str1;
    }
}

// initializing the game_board
void game_board_init(struct game_board* game_board, int rows, int cols)
{
    // dynamically alocating memory for the 2d array
    
    game_board->board = (struct game_piece **) malloc(rows *sizeof(struct patron *));
    
    for (int row = 0; row < rows; row++) {
        game_board->board[row] = (struct game_piece *) malloc(cols * sizeof(struct game_piece *));
    }
    
    // initiating each element to the defualt string
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            game_piece_init_default(&game_board->board[i][j]);
        }
    }
    // saving the dimensions of the array
    game_board->rows = rows;
    game_board->cols = cols;
    
}

// checks if a space is within the bounds of the board
int game_board_is_space_valid(struct game_board* game_board, int row, int col)
{
    
    if(row < 0 || col < 0)
    {
        return 0;
    }
    else if(row > game_board->rows || col > game_board->cols)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// checks if a space is full if not it will fill it and return true
// otherwise return false
int game_board_add_piece(struct game_board* game_board, struct game_piece* piece, int row, int col)
{
    char default_label[] = "---";
    char new_str[4];
    int result;
    strncpy(new_str, game_board->board[row][col].label, 3);
    new_str[3] = '\0';
    
    result = strcmp (new_str, default_label);
    
    // check if a space is full
    if(result == 0) // strcmp returns a zero if strings match
    {
        strcpy(game_board->board[row][col].label, piece->label);
        
        // return 1
        return 1;
    }
    else
    {
        return 0;
    }
}

// checks if there is an open spot and moves the struct to it
int game_board_move_piece(struct game_board* game_board, int src_row, int src_col, int dest_row, int dest_col)
{
    char default_label[4] = "---";
    char new_str[4];
    char new_str1[4];
    int result_1;
    int result_2;
    int return_int = 0;
    
    strncpy(new_str, game_board->board[src_row][src_col].label, 3);
    strncpy(new_str1, game_board->board[dest_row][dest_col].label, 3);
    
    new_str[3] = '\0';
    new_str1[3] = '\0';
    
    // check source
    result_1 = strcmp (new_str, default_label);
    result_2 = strcmp (new_str1, default_label);
    
    // if there is an element in the source
    // position then check if the destination
    // spot is open else return 0
    if (result_1 != 0)
    {
        // check if the destination is empty
        if(result_2 == 0)
        {
            strcpy(game_board->board[dest_row][dest_col].label, game_board->board[src_row][src_col].label);
            game_piece_init_default(&game_board->board[src_row][src_col]);
        }
    }
    else
    {
        // just setting return variable for consistency
        return_int = 0;
    }
    return return_int;
}

// prints the game_board to the console
void game_board_print(struct game_board* game_board)
{
//    char stirng[6];
    
    // iterates through the array
    for(int i = 0; i < game_board->rows; i++)
    {
        for (int j = 0; j < game_board->cols; j++) {
//            strcpy(stirng, game_board->board[i][j].label);
//            printf("%s ", stirng);
            printf("%s ", game_piece_to_string(&game_board->board[i][j]));
//            printf("%s ", game_board->board[i][j].label);
        }
        printf("\n");
    }
}

int main()
{
    /* declare local variables */
    int row;
    int col;
    int destRow;
    int destCol;
    int rowNum;
    int colNum;
    struct game_board board;
    struct game_piece piece;
    char input_string[30];

    /* get the size of the game board */
    printf("Please enter the number of rows.\n");
    scanf("%d", &rowNum);

    printf("Please enter the number of columns.\n");
    scanf("%d", &colNum);

    game_board_init(&board, rowNum, colNum);

    /* get the first piece's label */
    printf("Please enter a label for a new piece. Enter \"Q\" when done.\n");
    scanf("%s", input_string);

    game_board_print(&board);
    
    while (strcmp(input_string, "Q") != 0 && strcmp(input_string, "q") != 0)
    {
        game_piece_init(&piece, input_string);

        /* get the location to place the piece */
        printf("Please enter a row for the piece.\n");
        scanf("%d", &row);

        printf("Please enter a column for the piece.\n");
        scanf("%d", &col);

        /* verify the space is valid then add the piece to the board */
        if (game_board_is_space_valid(&board, row, col))
        {
            if (game_board_add_piece(&board, &piece, row, col))
            {
                printf("New piece \"%s\" added.\n", game_piece_get_label(&piece));
            }
            else
            {
                printf("A piece is already at that space.\n");
            }
        }
        else
        {
            printf("Invalid row and/or column.\n");
        }

        /* get the label for the next piece */
        printf("Please enter a label for a new piece. Enter \"Q\" when done.");
        scanf("%s", input_string);
    }

    /* print the board and check if user wants to move a piece */
    game_board_print(&board);
    printf("Would you like to move a piece? Enter \"Y\" to move a piece.\n");
    scanf("%s", input_string);

    while (strcmp(input_string, "Y") == 0 || strcmp(input_string, "y") == 0)
    {
        /* get the location of the piece */
        printf("Please enter the piece's row.");
        scanf("%d", &row);

        printf("Please enter the piece's column.");
        scanf("%d", &col);

        /* get the destination for the piece */
        printf("Please enter the piece's new row.");
        scanf("%d", &destRow);

        printf("Please enter the piece's new column.");
        scanf("%d", &destCol);

        /* verify both spaces are valid then move the piece */
        if (game_board_is_space_valid(&board, row, col) &&
            game_board_is_space_valid(&board, destRow, destCol))
        {
            if (game_board_move_piece(&board, row, col, destRow, destCol))
            {
                printf("Piece moved to new space.\n");
            }
            else
            {
                printf("A piece is already in that space.\n");
            }
        }
        else
        {
            printf("A row or column is invalid. No piece moved.\n");
        }

        /* print the board and check if the user wants move another piece */
        game_board_print(&board);
        printf("Would you like to move a piece? Enter \"Y\" to move a piece.\n");
        scanf("%s", input_string);
    }

    return 0;
}

