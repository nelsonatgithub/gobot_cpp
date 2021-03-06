using namespace std;

#include <cstddef>

#include "headers/errors.h"
#include "headers/gameStorage.h"

#define BOARD_SIZE 9
#define VARIATIONS_MAX 5

#define MOVE_NONE  0
#define MOVE_BLACK 1
#define MOVE_WHITE 2

struct move{
   int key;          // node identifier
   int pos_x;        // move position x
   int pos_y;        // move position y
   int who_played;
   // int score;        // score estimation
   // int value;        // move value
   move *next;       // pointer to next move
   // move *variation;  // pointer to a variation
}; // end node struct

class Game{

   public:
      
      int new_game(){
         first_move     = NULL;
         actual_move    = first_move;
         move_counter   = 0;
         whos_turn      = MOVE_BLACK;
         return 0;
         return ERROR_NONE;
      } // end - new_game
      
      int move_make(int pos_x, int pos_y){
         actual_move = new move;
         actual_move->key        = move_counter;
         actual_move->pos_x      = pos_x;
         actual_move->pos_y      = pos_y;
         actual_move->who_played = whos_turn;
         move_counter++;
         change_turn();
         return ERROR_NONE;
      } // end - move_make
      
      int move_undo(){
         actual_move = find_byKey(--move_counter);
         change_turn();
      } // end - move_undo
      
      int get_board(int board[BOARD_SIZE][BOARD_SIZE]){
         // int new_board[BOARD_SIZE][BOARD_SIZE];
         int pos_x, pos_y, who_played;
         move *move_pointer = first_move;
         while(move_pointer!=NULL){
            pos_x       = move_pointer->pos_x;
            pos_y       = move_pointer->pos_y;
            who_played  = move_pointer->who_played;
            board[pos_x][pos_y] = who_played;
            move_pointer = move_pointer->next;
         } // end - while
         // board = new_board;
         return ERROR_NONE;
      } // end - get_board
      
      Game(){
         first_move     = NULL;
         actual_move    = first_move;
         move_counter   = 0;
      } // end - Game constructor

   private:
      int move_counter;
      int whos_turn;
      
      move *first_move;    // specifies root
      move *actual_move;  // identifies the move
      
      // int add_move(){
      //    actual_move->next = new move;
      //    actual_move       = actual_move->next;
      //    actual_move->key  = move_counter;
      //    move_counter++;
      //    // actual_move->
      //    return ERROR_NONE;
      // } // end - add_move
      
      move *find_byPos (int pos_x, int pos_y){
         move *move_pointer = first_move;
         while(move_pointer->pos_x != pos_x && move_pointer->pos_y != pos_y){
            move_pointer = move_pointer->next;
         }
         return move_pointer;
      } // end - find_byPos
      
      move *find_byKey (int key){
         move *move_pointer = first_move;
         while(move_pointer->key != key){
            move_pointer = move_pointer->next;
         }
         return move_pointer;
      } // end - find_byPos
      
      int change_turn(){
         if (whos_turn==MOVE_BLACK) whos_turn = MOVE_WHITE;
         else                       whos_turn = MOVE_BLACK;
         return ERROR_NONE;
      } // end - change_turn

}; // end Game class