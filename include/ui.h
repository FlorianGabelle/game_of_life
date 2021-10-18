#ifndef UI_H
#define UI_H

class Ui {
        void clear_terminal();
    public:
        int read_board_size();
        bool read_randomize();
        int** read_user_board(int size);
        char read_command();
        void print_board(int** table, int size);
        void print_game_over();
        void print_quit_instruction();
};

#endif