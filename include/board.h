#ifndef BOARD_H
#define BOARD_H

class Board {
        int size;
        int** board_now;    // Holds the current values
        int** board_next;   // Holds the values for the next state
    public:
        Board(int board_size);
        Board(int** user_defined);
        ~Board();
        int** get_board();
        bool update();
};

#endif