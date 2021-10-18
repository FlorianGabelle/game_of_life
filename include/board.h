#ifndef BOARD_H
#define BOARD_H

class Board {
        int size;
        int** state_current;    // Holds the current values
        int** state_next;   // Holds the values for the next state
        void create_state_next();
    public:
        Board(int board_size);
        Board(int** user_defined, int board_size);
        ~Board();
        int** get();
        bool update();
};

#endif