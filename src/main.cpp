#include "../include/board.h"
#include "../include/ui.h"

#include <iostream>
#include <unistd.h>
#include <csignal>

using namespace std;

// game_state machine
enum {
    INIT_GAME,
    READ_COMMAND,
    NEXT_STATE,
    END_GAME
} game_state;
bool game_over, game_sequential;

// board
Board *board;
int board_size;
bool board_created = false;

// ui
Ui ui;
bool randomize;
int counter;
char user_input;

// interrupt
void signal_handler(int signal_number);

int main() {
    signal(SIGINT, signal_handler);     // register handling of C+c

    game_state = INIT_GAME;    
    game_over = false;
    game_sequential = true;
    counter = 0;

    do {
        switch(game_state) {
            case INIT_GAME:
                board_size = ui.read_board_size();
                randomize = ui.read_randomize();
                switch (randomize) {
                    case true:
                        board = new Board(board_size);
                        board_created = true;
                        break;
                    case false:
                        //board = new Board(ui.read_user_board(board_size));
                        board_created = true;
                        break;
                }
                ui.print_board(board->get_board(), board_size);
                game_state = READ_COMMAND;
                break;

            case READ_COMMAND:
                user_input = ui.read_next_command();
                switch (user_input) {
                    case 's':                           // Automatic progress
                        game_sequential = false;
                    case 'n':                           // Sequential progress
                        game_state = NEXT_STATE;
                        break;
                    case 'q':                           // Quit
                        game_state = END_GAME;
                        break;
                }
                break;

                case NEXT_STATE:
                game_over = board->update();
                ui.print_board(board->get_board(), board_size);
                if (game_over == true) {                // Game over
                    game_state = END_GAME;
                    break;
                } else if (game_sequential == true) {   // Sequential progress
                    game_state = READ_COMMAND;
                } else {                                // Automatic progress
                    cout << "Quit by pressing \"ctrl+C\"" << endl;
                    sleep(1);
                    game_state = NEXT_STATE;
                }
                break;

            case END_GAME:
                ui.game_over();
                game_over = true;
                break;
        }
    } while (game_over == false);
    
    delete board;

    return 0;
}

/**
 * Catches ctrl+C, quick and dirty quit game if inside automatic progress loop
 * 
 * @param[in] signal_number The signal number
 */
void signal_handler(int signal_number)  // 
{
    cout << "\n" << "QUIT" << endl;
    if (board_created)
        delete board;
    exit(signal_number);
}