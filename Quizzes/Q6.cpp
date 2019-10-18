/**
 * Quiz #
 * Sequential data
 * 1. List the design recipe steps in order
 * 2. Implement `filterOdd`
 **/

#include <vector>
#include <string>
#include <cassert>
#include <iostream>

using namespace std;

// Creates a vector containing the even numbers in the input vector.
// Input
// v - The vector to filter
// Output
// A new vector containing only the evens in v
vector<int> filterOdd(vector<int> v);

string vtos(vector<int> v);
void test();

int main() {
  vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
  test();
  cout << -3 % 2 << endl;
  cout << vtos(filterOdd(v)) << endl;
  return 0;
}

void test() {
  assert(filterOdd({1,2,3,4}) == vector<int>({2,4}));
  // -3 % 2 == 1
  assert(filterOdd({-4,-2}) == vector<int>({-4,-2}));
  assert(filterOdd({0}) == vector<int>({0}));
  assert(filterOdd({6,8}) == vector<int>({6,8}));
  assert(filterOdd({}) == vector<int>({}));
  return;
}

vector<int> filterOdd(vector<int> v) {
  // Make an output vector
  vector<int> out = {};
  int i = 0;
  while(i < v.size()) {
    // Check if each element is odd or even
    if(v[i] % 2 == 0) {
      // put even elements in the output vector
      out.push_back(v[i]);
    }
    i = i + 1;
  }
  // return the result
  return out;
}

string vtos(vector<int> v) {
  int i = 0;
  string out = "{ ";
  while(i < v.size()) {
    out = out + to_string(v[i]) + ", ";
    i = i + 1;
  }
  out.erase(out.length()-2,1);
  return out + "}";
}
