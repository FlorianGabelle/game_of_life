#ifndef UI_H
#define UI_H

class Ui {
    
    public:
        int read_board_size();
        bool read_randomize();
        //int** read_user_board(int board_size);
        char read_next_command();
        void print_board(int** table, int size);
        void game_over();
};

#endif