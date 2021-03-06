# GoBot V0.01

## Description
This program is meant to be a simple, a priori, Go game bot program written in C++ language, which will play Go at online servers. An AI is to be implemented to solve 9x9 games. At first it will have CLI only and HTTP network interface. Later a Python Qt GUI and browser GUI may be implemented. The objective is to learn and get experience with C++ implementations as we program for the game of Go.

## TODOs
   - Controller
      - Implement proper state machine model
      - Implement parallel processing structure
   - User Interface
      - Finish CLI board with cout properly
      - Implement Python TKinter interface GUI
      - Implement WebAssembly, HTML and CSS interface GUI
   - Computer AI
      - Implement some random moves generator
      - Implement floodfill algorithm for score estimator
      - Search a good AI algorithm to implement
   - GameStorage
      - Revise strutures to store the game history and possible moves
      - Implement undo move
   - Network Communication Interface
      - Implement communication on HTTP protocol to online-go.com
      - Implement communication with KGS (maybe)
      - find other servers for the bot to play

## Usage
test and debug mode only.

## Components

1. Game Storage (STO)
   - Stores the game history and possible sequences
   - Stores the game actual position
   - atributtes value to board positions
   - Presents an interface to manipulate the game
      - user can play a move
      - user can undo a move

2. User Interface (UI)
   - CLI: command line interface
      - CMD_MOVE:    user wants to play move
      - CMD_STAT:    user wants to see game status
      - CMD_UNDO:    user wants to undo move
      - CMD_BOARD:   user wants to see board
      - CMD_EXIT:    user wants to quit the program

3. Main Controller (MC)
   - Implements state machine model
   - Reads and Processes interface commands

4. Computer Artificial Intelligence (CAI)
   - choose a move given the several possible sequences and related score estimations (AI_1)
   - estimate score given a board position (AI_1)
   - guess possible sequence of moves before proper estimation (AI_2)
   - guess possible move before a proper estimation (AI_2)
   
*) AI_N indicates importance order

## MVC Architeture
   - Model: STO
   - View: UI
   - Controller: MC and CAI

We separated CAI from MC so that CAI can be given special attention.

## State Machine

When the program runs, it waits in iddle mode, waiting the user to input a command.
Main commands are supposed to be:

1. show game status
2. choose move / undo
3. estimate score
4. load / save game
5. help
6. exit

## Log History so far
   - 16 Feb: Initial commit and struture definition
   - 17 Feb: Initial implementation of CLI user interface
   - 18 Feb: Initial implementation of game storage
