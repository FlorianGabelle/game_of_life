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
    clear_terminal();

    do {
        correct = true;
        cout << "ENTER_SIZE (Value between 0 and 50)" << endl;
        getline (cin, str);
        for (auto c : str) {        // check if digit
            if (!isdigit(c)) {
                correct = false;
                cout << "ERROR: Wrong input" << endl;
                break;
            }
        }
        if (correct) {              // check if value of digit is correct
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
    clear_terminal();
    
    while (true) {
        cout << "Do you want to randomize the state of the cells ? (y/n):" << endl;
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
int** Ui::read_user_board(int size) {
    int **user_board = new int*[size];

    for(int i = 0; i < size; i++)
        user_board[i] = new int[size];

    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++) {
            char input;
            clear_terminal();
            cout << "Enter \"1\" if you want to set the state of the current cell as alive." << endl;
            cout << "Enter anything else to leave the cell as dead." << endl;
            print_quit_instruction();
            cout << "Current cell [" << i+1 << "," << j+1 << "] state : ";
            cin >> input;
            if(input == '1')
                user_board[i][j] = 1;
            else
                user_board[i][j] = 0;
        }

    return user_board;
}

/**
 * Reads what the user wants to do next.
 *
 * @returns a char, either 's', 'n' or 'q'
 */
char Ui::read_command() {
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
 * Prints the board given as input.
 * 
 * @param[in] board the board to be printed
 * @param[in] size the size of the board to be printed
 */
void Ui::print_board(int** board, int size) {
    clear_terminal();

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
void Ui::print_game_over() {
    cout << "Game over" << endl;
}

/**
 * Prints the quit message.
 */
void Ui::print_quit() {
    cout << "\nQUIT" << endl;
}

/**
 * Clears the terminal.
 */
void Ui::clear_terminal() {
    cout << "\033c";
}

/**
 * Prints quit instruction.
 */
void Ui::print_quit_instruction() {
    cout << "You can quit by pressing \"ctrl+C\"" << endl;
}