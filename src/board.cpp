#include "../include/board.h"

#include <stdlib.h>

/**
 * Board class default constructor.
 * Creates the board and fills it with random values.
 *
 * @param[in] board_size the size of the board to create
 */
Board::Board(int board_size) {
    size = board_size;
    board_now = new int*[size];         // columns

    for(int i = 0; i < size; i++)
        board_now[i] = new int[size];   // rows

    for(int i = 0; i < size; i++)      
        for(int j = 0; j < size; j++)
            board_now[i][j] = rand() % 2; 
}

/**
 * Board class overloaded constructor.
 * Initialises the board using the one defined by the user.
 *
 * @param[in] user_defined the board defined by the user
 */
Board::Board(int** user_defined) {
    board_now = user_defined;
}

/**
 * Board class destructor.
 * Frees what needs to be.
 */
Board::~Board() {
    // Free memory
    for(int i = 0; i < size; i++)
        delete board_now[i];

    delete board_now;
}

/**
 * Retrieves the current board.
 * 
 * @returns the current board
 */
int** Board::get_board() {
    return board_now;
}

/**
 * Computes the next state of the board.
 * Uses a second board to temporarily store the next states
 * Overwrites the current board with the next state one at the end of its operations
 * so the board_now is always current
 * 
 * @returns true if the board still has at least one cell alive
 */
bool Board::update() {
    int alive_n = 0;
    /*
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
        {
            int alive_neighbours = 0;
            for (int k = i-1; k <= i+1; k++)
                for (int l = j-1; l <= j+1; l++)
                    alive_neighbours += board_now[k][l];
            alive_neighbours -= board_now[i][j];

            if(board_now[i][j] == 1 && (alive_neighbours <= 1 || alive_neighbours >= 4))
                board_now[i][j] = 0;
            else if(board_now[i][j] == 0 && alive_neighbours == 3)
                board_now[i][j] = 1;

            // Count live cells
            alive_n += board_now[i][j];
        } 
    return alive_n;*/

    return false;
}