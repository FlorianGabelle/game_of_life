# Game of Life

The purpose of this project was to showcase my abilities at writing a simple program with the C++ language.
I have been out of practice for a while, so this was a fun way to get back to programming.

Its main functionalities have been split to ensure the code is easy to read and modify.

## Description

This game implements the [Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) that was originally created by the british mathematician Horn Horton Conway in 1970. 

The user interface offers the following choices during the course of the game:

* Choosing the size of the game board.
* Randomizing the game board (if not, the user must enter it manually).
* After each state update, the user is prompted to chose whether to continue the game sequentially, automatically or to quit.

## Getting Started

### Dependencies

This program makes use of the following C and C++ libraries

* csignal
* iostream
* stdlib
* string
* unistd

### Compiling and building the program

From the project folder, run the following command to compile the program using g++ (tested under Ubuntu 20.04.3 LTS).

```
g++ src/* -o life
```

### Executing program

From the project folder, run the following command to execute the program.

```
./life
```

## Author

Florian Gabelle

## Version History

* 0.4
    * The user can now input the state of the cells himself.
    * Refactoring to help readability.
    * Minor fixes

* 0.3 
    * Corrected the behavior when the game ends.

* 0.2
    * Implemented the main logic to update the game board.
    * Added a handler to quit the game by pressing ctrl + C (for the automatic progress forever loop).
        * A better approach would have been to run a separate thread + callback to allow for non blocking polling of keyboard input.
* 0.1
    * Initial commit, missing some blocks to allow full functionality.
    * Provides the main logic in the form of a state machine.
    * Provides the almost complete UI.
    * Provides the Board class performing the operations related to the game board.

## License

This project is licensed under the MIT License - see the LICENSE.md file for details

## Acknowledgments

Here are the people whose code snippets helped me build this project
* [AraK](https://stackoverflow.com/a/1946866)
* [cplusplus.com](https://www.cplusplus.com/reference/csignal/signal/?kw=signal)