#include "../include/ui.h"

#include <iostream>
#include <string>

using namespace std;

/**
 * Reads user input and ensures it is a value between 0 a 50.
 *
 * @returns an int between 0 and 50
 */
int Ui::read_board_size() {
    int size;
    string str = {};
    bool correct = true;

    do {
        correct = true;
        cout << "ENTER_SIZE (Value between 0 and 50)" << endl;
        getline (cin, str);
        for (auto c : str) {    // check 
            if (!isdigit(c)) {
                correct = false;
                cout << "ERROR: Wrong input" << endl;
                break;
            }
        }
        if (correct) {
            size = stoi(str);
            if(size > 50) {
                correct = false;
                cout << "ERROR: Size over 50" << endl;
            }
        }
    } while (correct == false);

    return size;
}

/**
 * Reads if the user wants to randomize the board.
 *
 * @returns true if the board should be randomized
 */
bool Ui::read_randomize() {
    char user_input;
    
    while (true) {
        cout << "Randomize (y/n):" << endl;
        cin >> user_input;
        switch (user_input) {
            case 'y':
                return true;
            case 'n':
                return false;
            default:                            // Error
                cout << "ERROR: Wrong input" << endl;
        }
    }
}

/**
 * Reads the state for each cell from the user.
 *
 * @returns the bidimensional array containing the user values
 */
/* int** Ui::read_user_board(int board_size) {
    return board;
} */

/**
 * Reads what the user wants to do next.
 *
 * @returns a char, either 's', 'n' or 'q'
 */
char Ui::read_next_command() {
    char user_input;
    
    while (true) {
        cout << "Enter \"s\" to start the game." << endl;
        cout << "Enter \"n\" to advance to the next state" << endl;
        cout << "Enter \"q\" to quit the game" << endl;
        cin >> user_input;
        switch (user_input) {
            case 's':
            case 'n':
            case 'q':
                return user_input;
            default:
                cout << "ERROR: Wrong input" << endl;
                break;
        }
    }

    return user_input;
}

/**
 * Reads what the user wants to do next.
 * 
 * @param[in] board the board to be printed
 * @param[in] size the size of the board to be printed
 */
void Ui::print_board(int** board, int size) {
    cout << "\033c";    // Clear terminal

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
            cout << (board[i][j] ? "* " : "  ");
        cout << endl;
    }
}

/**
 * Prints the game over message.
 */
void Ui::game_over() {
    cout << "Game over" << endl;
}