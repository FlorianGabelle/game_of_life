#include "../include/board.h"
#include "../include/ui.h"

#include <iostream>
#include <unistd.h>

using namespace std;

// game_state machine
enum {
    INIT_GAME,
    NEXT_STATE,
    READ_COMMAND,
    END_GAME
} game_state;
bool game_over, game_sequential;

// board
Board *board;
int board_size;

// ui
Ui ui;
bool randomize;
int counter;
char user_input;

int main() {
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
                        break;
                    case false:
                        //board = new Board(ui.read_user_board(board_size));
                        break;
                }
                ui.print_board(board->get_board(), board_size);
                game_state = NEXT_STATE;
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
                    cout << counter++ << endl;
                    sleep(1);
                    game_state = NEXT_STATE;
                }
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

            case END_GAME:
                ui.game_over();
                game_over = true;
                break;
        }
    } while (game_over == false);
    
    delete board;

    return 0;
}