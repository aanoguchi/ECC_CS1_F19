/**
 * Quiz 5
 * 1. List all of the steps in the design recipe in *order*.
 *
 *   a. Purpose Statement - Describe _what_
 *   b. IO - Data types and _what_ (not how).
 *   c. Header - Function declaration
 *   d. Unit tests - Asserts
 *   e. Pseudocode - Big picture, not every line. Don't just
 *                   repeat what your code is doing, we can see.
 *   f. Code - Implement your pseudocode plan.
 *
 * Use the desgin recipie to write a function which calculates
 * the distance
 * between two points represented by the following `Point` struct.
 *
 * You may use an arrow shorthand for asserts:
 * `input1 input2 ... inputN -> output`
 **/

#include <iostream>
#include <cassert>

using namespace std;

struct Point {
  double x;
  double y;
};

// Find the distance between two cartesian points
// Input
// a - the first point
// b - the second point
// Output
// the distance between `a` and `b`
double distance(Point a, Point b);
void test_distance();

int main() {
  test_distance();
  Point a = { 1, 1 };
  Point b = { 4, 5 };
  cout << distance(a, b) << endl;
  return 0;
}
double distance(Point a, Point b){
  // Get the legs of the triangle formed by a and b
  double adjacent = b.x - a.x;
  double opposite = b.y - a.y;
  // Use the pythagorean theorem to calculate the hypotenuse
  return sqrt(pow(adjacent,2) + pow(opposite, 2));
}
void test_distance() {
  assert(distance({0.0,0.0},{21.0, 20.0}) == 29.0);
  // On a _paper test_ if you can't create a test without a calculator
  // you can use code to define the behaviour.
  assert(distance({5.0,-4.0},{10.0, 20.0} == sqrt(25 + pow(24,2)));
}
