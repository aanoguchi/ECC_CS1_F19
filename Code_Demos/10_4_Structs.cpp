#include <iostream>

using namespace std;

struct Point {
  double x;
  int y;
};
enum class TL {G, Y, R};

void f(TL t);

int main() {
  Point p = { 10, 20 };
  TL t;
  cout << printTL(t);
  return 0;
}

string printTL(TL t) {
  string out;
  if(t == TL::G) {
    //return green
    out = "green";
  } else if(t == TL::Y) {
    // return yellow
    out = "yellow";
  } else if(t == TL::R) {
    // return red
    out = "red";
  }
  return out;
}
void f(TL t, Point p) {
  if(t == TL::G) {
    //Go
    ... p.x ... p.y ...
  } else if(t == TL::Y) {
    // Go faster
  } else if(t == TL::R) {
    // Go wait no stop!
  }
}
