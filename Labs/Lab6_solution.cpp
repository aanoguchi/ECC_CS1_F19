/**
 * Instructions: *Using the design recipie*,
 * implement the missing code by following the TODO tags.
 **/

/**
 * Tic-Tac-Toe
 *
 * Allows a user to play a game of tic tac toe in the terminal against a
 * computer.
 *
 **/

#include <string>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;
/**
 * Data definitions
 **/

// A Location represents the index of a space on a tic-tac-toe board in the
// following configuration:
// 0|1|2
// -+-+-
// 3|4|5
// -+-+-
// 6|7|8
using Location = int;

// A Space represents the possible values within one space on the tic-tac-toe
// board.
enum class Space {Empty, X, O};


// A Row represents one row of 3 spaces on the tic-tac-toe board
struct Row {
  Space left, center, right;
};
const Row BLANK_ROW = { Space::Empty, Space::Empty, Space::Empty };
// A Board consists of 3 rows of spaces
struct Board {
  Row top, middle, bottom;
};
const Board BLANK_BOARD = { BLANK_ROW, BLANK_ROW, BLANK_ROW };
/**
 * Functions
 **/

//// Initializers
Space c_to_space(char c);
Row s_to_row(std::string s);
Board s_to_board(std::string s);

//// Convert data types to string format
void test_space_to_s();
string space_to_s(Space s);
void test_row_to_s();
string row_to_s(Row r);
void test_board_to_s();
string board_to_s(Board b);

//// Interface message generators
void test_gamestate_message();
string gamestate_message(Board b, Space turn);
void test_end_game_message();
string end_game_message(Board b, Space win);

//// Get moves
Location get_move(Board b, Space turn);
void test_compute_move();
Location compute_move(Board b, Space turn);

//// Getters
Space get_space(Board b, Location l);
Space get_space(Row b, Location l);

//// Setters
Board set_space(Board b, Location l, Space s);
Row set_space(Row r, Location l, Space s);


//// Game mechanics
bool full(Board b);
bool full(Row r);
bool full(Space s);

vector<Row> flay(Board b);
vector<Row> flay_rows(Board b);
vector<Row> flay_cols(Board b);
vector<Row> flay_diags(Board b);

Space winner(Board b);
Space winner(Row r);

bool is_game_over(Board b);
Space next_turn(Space t);
//// Template Functions
void test();
void run();
void run_game();

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
  return 0;
}
void run() {
  // Variable Declarations
  char again = 'y';
  while(again == 'y') {
    run_game();
    cout << "Play again? [y/n] " << endl;
    cin >> again;
  }
}
void test() {
  // TODO Implement these!
  test_space_to_s();
  test_row_to_s();
  test_board_to_s();
  test_gamestate_message();
  test_end_game_message();
  test_compute_move();
 }
void run_game() {
  // Initial game state with blank board and player one first.
  Board b = BLANK_BOARD;
  Space turn = Space::O;
  Location move;

  while(!is_game_over(b)) {
    // Human player
    if(turn == Space::O) {
      // Show player the board
      cout << gamestate_message(b, turn) << endl;
      move = get_move(b, turn);
    // Computer
    } else {
      move = compute_move(b, turn);
    }
    b = set_space(b,move,turn);
    turn = next_turn(turn);
  }
  cout << end_game_message(b, winner(b)) << endl;
  return;
}




//// Printers

// Converts a Space to a string
// Input
// s - the space to convert
// Output
// a string representing s
void test_space_to_s() {
  assert(space_to_s(Space::Empty) == " ");
  assert(space_to_s(Space::X) == "x");
  assert(space_to_s(Space::O) == "o");
}
string space_to_s(Space s) {
  string o;
  if(s == Space::Empty) {
    o = " ";
  } else if(s == Space::X) {
    o = "x";
  } else {
    o = "o";
  }
  return o;
}
// Converts a row to a string
// Input
// r - the row to convert
// Output
// the string representation of r
void test_row_to_s() {
  Row r = { Space::Empty, Space::Empty, Space::Empty };
  assert(row_to_s(r) == "   |   |   ");
  r = { Space::X, Space::O, Space::Empty };
  assert(row_to_s(r) == " x | o |   ");
}
string row_to_s(Row r) {
  return " " + space_to_s(r.left) + " | " +
    space_to_s(r.center) + " | " +
    space_to_s(r.right) + " ";
}

// Converts a board to a string
// Input
// b - the board to convert
// Output
// the string representing b
void test_board_to_s() {
  Board b =
    { {Space::Empty, Space::Empty, Space::Empty},
      {Space::Empty, Space::Empty, Space::Empty},
      {Space::Empty, Space::Empty, Space::Empty} };
  assert(board_to_s(b) ==
    "   |   |   \n---+---+---\n   |   |   \n---+---+---\n   |   |   ");
  b =
    { {Space::X, Space::Empty, Space::X},
      {Space::X, Space::O, Space::Empty},
      {Space::O, Space::Empty, Space::Empty} };

  assert(board_to_s(b) ==
    " x |   | x \n---+---+---\n x | o |   \n---+---+---\n o |   |   ");
}
string board_to_s(Board b) {
  return row_to_s(b.top) + "\n---+---+---\n" +
    row_to_s(b.middle) + "\n---+---+---\n" +
    row_to_s(b.bottom);
}

// Creates an end game message, reporting the winner and including the
// end game board state.
// Input
// b - the board representing the final game state
// win - who was the winner? `Empty` means it's a cat's game
// Output
// A string containing an end game message
void test_end_game_message() {
  Board b =
    { {Space::X, Space::X, Space::X},
      {Space::O, Space::Empty, Space::Empty},
      {Space::O, Space::O, Space::Empty} };
  string s =
    "Game Over\n x | x | x \n---+---+---\n o |   |   \n---+---+---\n o | o |   \nThe winner was x!";
  assert(end_game_message(b, Space::X) == s);
  b =
    { {Space::X, Space::O, Space::X},
      {Space::O, Space::X, Space::O},
      {Space::O, Space::X, Space::O} };
  s =
    "Game Over\n x | o | x \n---+---+---\n o | x | o \n---+---+---\n o | x | o \nIt's a cats game...";
  assert(end_game_message(b, Space::Empty) == s);
}
string end_game_message(Board b, Space win) {
  string o = "Game Over\n" +
    board_to_s(b);
  // It's a cats game
  if(win == Space::Empty) {
    o = o + "\nIt's a cats game...";
  } else {
    o = o + "\nThe winner was " + space_to_s(win) + "!";
  }
  return o;
}
// creates a string reflecting the state of the game
// Input
// b - the current board
// turn - who's turn it is
// Output
// A string message reflecting the state of board and turn
void test_gamestate_message() {
  Board b =
    { {Space::X, Space::O, Space::X},
      {Space::O, Space::Empty, Space::O},
      {Space::O, Space::X, Space::O} };
  string s =
    "x's move:\n x | o | x \n---+---+---\n o |   | o \n---+---+---\n o | x | o \nThe winner was x!";
  assert(gamestate_message(b, Space::X).compare(s));
}
string gamestate_message(Board b, Space turn){
  return space_to_s(turn)+"'s move:\n"+board_to_s(b)+"\n";
}

//// Get moves
// Gets the player's next move.
// Input
// b - the current board state
// turn - who's turn it is
// Output
// the move the user would like to make
Location get_move(Board b, Space turn) {
  Location l = 0;
  cin >> l;
  return l;
}
// A simple ai which returns a valid play based on the board
// and which turn it is.
// Input
// b - The current state of the game
// turn - is the AI x or o?
// Output
// A valid location
// Note: this ai will play in the first available space starting from the top
// right.
void test_compute_move() {
  Board b =
    { {Space::Empty, Space::Empty, Space::Empty},
      {Space::Empty, Space::Empty, Space::Empty},
      {Space::Empty, Space::Empty, Space::Empty} };
  assert(compute_move(b, Space::X) == 0);
  b =
    { {Space::X, Space::Empty, Space::Empty},
      {Space::Empty, Space::Empty, Space::Empty},
      {Space::Empty, Space::Empty, Space::Empty} };
  assert(compute_move(b, Space::O) == 1);
  b =
    { {Space::X, Space::O, Space::O},
      {Space::O, Space::X, Space::X},
      {Space::X, Space::O, Space::O} };
  assert(compute_move(b, Space::O) == -1);
}
Location compute_move(Board b, Space turn) {
  int i = 0;
  while(i < 9) {
    if(get_space(b,i) == Space::Empty) {
      return i;
    }
    i = i + 1;
  }
  // an error occured, there are no valid spaces.
  return -1;
}


/**
 *
 *
 *
 *
 *
 *
 *
 * Don't worry too much about this stuff down here
 *
 **/

//// Initializers
Space c_to_space(char c) {
  if(c == ' ') {
    return Space::Empty;
  } else if(c == 'x') {
    return Space::X;
  } else {
    return Space::O;
  }
}
Row s_to_row(string s) {
  return { c_to_space(s[0]),
           c_to_space(s[1]),
           c_to_space(s[2]) };
}
Board s_to_board(string s) {
  return { s_to_row(s.substr(0,3)),
           s_to_row(s.substr(3,3)),
           s_to_row(s.substr(6,3)) };
}

//// Getters
Space get_space(Board b, Location l) {
  int row = l / 3;
  Space result;
  if(row == 0) {
    result = get_space(b.top, l);
  } else if(row == 1) {
    result = get_space(b.middle, l);
  } else {
    result = get_space(b.bottom, l);
  }
  return result;
}
Space get_space(Row r, Location l) {
  int col = l % 3;
  Space result;
  if(col == 0) {
    result = r.left;
  } else if(col == 1) {
    result = r.center;
  } else {
    result = r.right;
  }
  return result;
}

//// Setters
Board set_space(Board b, Location l, Space s){
    int row = l / 3;
    if(row == 0) {
      b.top = set_space(b.top, l, s);
    } else if(row == 1) {
      b.middle =  set_space(b.middle, l, s);
    } else {
      b.bottom = set_space(b.bottom, l, s);
    }
    return b;
}
Row set_space(Row r, Location l, Space s){
    int col = l % 3;
    Row result = r;
    if(col == 0) {
      result.left = s;
    } else if(col == 1) {
      result.center = s;
    } else {
      result.right = s;
    }
    return result;
}


//// Game mechanics
bool full(Board b){
  return full(b.top) && full(b.middle) && full(b.bottom);
}
bool full(Row r) {
  return full(r.left) && full(r.center) && full(r.right);
}
bool full(Space s) {
  return s != Space::Empty;
}

// Get every row, col, and diagonal as a vector
vector<Row> flay(Board b) {
  vector<Row> v(8);
  vector<Row> s = flay_rows(b);
  v.insert(v.end(), s.begin(), s.end());
  s = flay_cols(b);
  v.insert(v.end(), s.begin(), s.end());
  s = flay_diags(b);
  v.insert(v.end(), s.begin(), s.end());
  return v;
}
vector<Row> flay_rows(Board b) {
  return { b.top, b.middle, b.bottom };
}
vector<Row> flay_cols(Board b) {
  return { { b.top.left, b.middle.left, b.bottom.left },
           { b.top.center, b.middle.center, b.bottom.center },
           { b.top.right, b.middle.right, b.bottom.right } };
}
vector<Row> flay_diags(Board b) {
  return { { b.top.left, b.middle.center, b.bottom.right },
           { b.top.right, b.middle.center, b.bottom.left } };
}
// Returns Empty for a cats or a game that hasn't endend. Use `full` to check
// for cats
Space winner(Board b) {
  vector<Row> f = flay(b);
  Space win;
  for(int i = 0; i < f.size(); i++) {
    win = winner(f[i]);
    if(win != Space::Empty) {
      return win;
    }
  }
  return Space::Empty;
}

Space winner(Row r) {
  if(r.left == r.center && r.center == r.right) {
    return r.left;
  } else {
    return Space::Empty;
  }
}

bool is_game_over(Board b) {
  return full(b) || winner(b) != Space::Empty;
}
Space next_turn(Space t) {
  return static_cast<Space>((static_cast<int>(t) % 2) + 1);
}
