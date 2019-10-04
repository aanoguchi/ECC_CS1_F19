/**
 *
 * Allows a user to play a game of tic tac toe in the terminal against a
 * computer.
 *
 * Implement the code labeled TODO
 * you may use any other functions defined in the program.
 *
 **/

#include <iostream>
#include <cassert>
#include <string>

using namespace std;

/**
 * Data Definitions
 **/

using Location = int;

enum class Player {One, Two};

enum class Space {Empty, X, O};
struct Row {
  Space left, center, right;
};
struct Board {
  Row top, middle, bottom;
};
/**
 * Function Declarations
 **/

// AI
// TODO Using the complete design recipie implement an AI which chooses the next
// location to play given the current state of the board.
Location compute_move(Board b);
// Turns
Player next_turn(Player current_turn);
// Validate moves
bool is_valid(Board b, Player turn, Location move);

Space get_space(Board b, Location l);

// Interface
//// Select a location
Location get_move(Board b);
//// Print out gamestate
void print_gamestate(Board b);
/**
 * TODO Use the design recipie to implement the to_s
 * functions
 * Example string format
 * x | o |
 *---+---+---
 * o | x |
 *---+---+---
 *   |   |o
 */
string board_to_s(Board b);
string row_to_s(Row r);
string space_to_s(Space s);

string player_to_s(Player p);
// Report winner
string end_game_message(Board b, Player winner);
//// Detect win condition
bool is_game_over(Board b);

/**
 * V1 features
 **/
// Scoreboard
// Exit game
void test();
void run();

/**
 * Main Function
 **/

int main() {
  char t;

  cout << "Enter [t] to test, or any other character to run." << endl;
  cin >> t;
  if(t == 't') {
    test();
  } else {
    run();
  }
}

/**
 * Function Definitions
 **/

void test() {

}

void run() {
  // Variable Declarations

  // Input

  // Output

}
string row_to_s(Row r) {
  return "";
}
string board_to_s(Board b) {
  return row_to_s(b.top) + "\n" +
         row_to_s(b.middle) + "\n" +
         row_to_s(b.bottom)  + "\n";
}

Player next_turn(Player current_turn) {
  Player next_player;
  if(current_turn == Player::One) {
    next_player = Player::Two;
  } else if(current_turn == Player::Two) {
    next_player = Player::One;
  }
  return next_player;
}
Space get_space_from_row(Row r, Location l) {
  return Space::Empty;
}
Space get_space(Board b, Location l) {
  int row = l / 3;
  Space result;
  if(row == 0) {
    result = get_space_from_row(b.top, l);
  } else if(row == 1) {
    result = get_space_from_row(b.middle, l);
  } else {
    result = get_space_from_row(b.bottom, l);
  }
  return result;
}
