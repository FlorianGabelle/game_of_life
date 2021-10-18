#include "../include/board.h"

#include <stdlib.h>

/**
 * Board class default constructor.
 * Creates the board and fills it with random values.
 *
 * @param[in] board_size the size of the board to create
 */
Board::Board(int board_size) : size(board_size) {
    state_current = new int*[size];         // columns

    for(int i = 0; i < size; i++)
        state_current[i] = new int[size];   // rows

    for(int i = 0; i < size; i++)      
        for(int j = 0; j < size; j++)
            state_current[i][j] = rand() % 2;
    
    create_state_next();
}

/**
 * Board class overloaded constructor.
 * Initialises the board using the one defined by the user.
 *
 * @param[in] user_defined the board defined by the user
 * @param[in] board_size the size of the board to create
 */
Board::Board(int** user_defined, int board_size): size(board_size) {
    state_current = user_defined;
    create_state_next();
}

void Board::create_state_next() {
    state_next = new int*[size];         // columns

    for(int i = 0; i < size; i++)
        state_next[i] = new int[size];   // rows
}

/**
 * Board class destructor.
 * Frees what needs to be.
 */
Board::~Board() {
    // Free memory
    for(int i = 0; i < size; i++)
        delete state_current[i];

    delete state_current;
}

/**
 * Retrieves the current board.
 * 
 * @returns the current board
 */
int** Board::get() {
    return state_current;
}

/**
 * Computes the next state of the board.
 * Uses a second board to temporarily store the next states
 * Overwrites the current board with the next state one at the end of its operations
 * so the board_now is always current
 * 
 * @returns false if the board still has at least one cell alive
 */
bool Board::update() {
    int alive_n = 0;
    
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
        {
            int alive_neighbours = 0;
            for (int k = i-1; k <= i+1; k++)
                for (int l = j-1; l <= j+1; l++)
                    if((k >= 0) && (k < size) && (l >= 0) && (l < size))
                        alive_neighbours += state_current[k][l];
            alive_neighbours -= state_current[i][j];

            if(state_current[i][j] == 1 && (alive_neighbours <= 1 || alive_neighbours >= 4))
                state_next[i][j] = 0;
            else if(state_current[i][j] == 0 && alive_neighbours == 3)
                state_next[i][j] = 1;

            // Count live cells
            alive_n += state_current[i][j];
            
        }

    // Transfer the next state to the current board
    state_current = state_next;

    return !alive_n;
}