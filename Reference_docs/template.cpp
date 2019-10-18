/**
 * 
 * Standard Header
 *
 **/

#include <iostream>
#include <cassert>
#include <string>

using namespace std;

/**
 * Data Definitions 
 **/

enum class Player {One, Two};

enum class Location {Topfe

enum class Space {Empty, X, O};
struct Row {
  Space Left, Center, Right;
}
struct Board {
  Row Top, Middle, Bottom;
}

/**
 * Function Declarations
 **/

void test();
void run();

// TODO Implement the following functions
string player_to_s(Player p);

string space_to_s(Space s);
string row_to_s(Row r);
string board_to_s(Board b);

Player next_turn(Player p);
Board play(Board b, Player p, 
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
