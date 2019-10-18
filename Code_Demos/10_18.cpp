#include <string>
#include <iostream>
#include <cassert>

using namespace std;

// Creates a string which is the reverse of an input string
// Input
// s - the string to reverse
// Output
// the reverse of `s`
string reverse_s(string s);
void test_reverse_s();

int main(void) {
  test_reverse_s();
  
  cout << reverse_s("racecar") << endl;
  return 0;
}

void test_reverse_s() {
  assert(reverse_s("string").compare("gnirts"));
  assert(reverse_s("").compare(""));
  assert(reverse_s("\n white space").compare("ecaps etihw \n"));
}
string reverse_s(string s) {
  string out(' ', s.length());
  int i = 0;
  // For every element in s put it in the reverse location in out
  while(i < s.length()) {
    out[s.length() - (1 + i)] = s[i];
    i = i + 1;
  }
  return out;
}
