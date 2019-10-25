/**
 * Quiz 7
 * Strings
 * 1. Read the comments given for `averageWordLen`
 *    Imagine a function which would help you implement it.
 * TODO: Split questions
 *    Write the name and purpose statement for your imaginary function.
 * 2. Implement `averageWordLen`
 **/

#include <string>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

// Finds the length of each string in a vector of strings
vector<int> countOfWords(vector<string> words);
// Finds the sum of numbers in a vector
double sum(vector<double> nums);
vector<string> splitByWords(string s);

// Purpose:
// Calculates the average length of each word in a string
// IO:
// Input
// s - a string of words separated by whitespace
// Output
// the average length of each word as a
// Header:
double averageWordLen(string s);
void test();

int main() {
  test();
  cout << averageWordLen("The quick brown fox jumps over the lazy dog.")
       << endl;
  return 0;
}

void test() {
  assert(averageWordLen("Hello World") == 5.0);
  assert(averageWordLen("Good Morning") == 11.0 / 2.0);
  assert(averageWordLen("$%#@!") == 0);
  assert(averageWordLen("") == 0);
  assert(averageWordLen("$%## a bcd") == 2.0);
  assert(averageWordLen("ao#*$aaab") == 3.0);
  return;
}

/**
 * Example paper answer format

---
2.
* On paper, write your tests in the form `a -> b`
* corresponding to: assert(averageWordLen(a) == b);
Tests:
"Hello World!" -> 5.0
"Good Morning" -> 5.5555
"" -> 0
"$%#@!" -> 0
"$%## a bcd" -> 2
"ao#*$aaab" -> 3
Template:
... s ...
or
int i = 0;
while(i < s.l ength()) {
  ... s[i] ...
  i = i + 1;
 }
Psuedocode:
# Convert s to a vector of words
# Count the number of letters in each word
# Find the sum of the counts
# Divide the sum by the number of words
---

* Example helper function paper format:
* N.b.
* While you do not need to show the full design recipe, it can be a good way of
* demonstrating partial understanding. For helper functions, if you are able, 
* you may simply write the code with appropriate comments.

Question 10
Helper function: splitByWords
Purpose:
I/O:
Header:
Tests:
Template:
Psuedocode:
Code:

**/

double averageWordLen(string s) {
  double total;
  vector<int> counts;
  int count;
  vector<string> words;
  //Convert s to a vector of words
  words = splitByWords(s); // Not sure how to implement this
  //Count the number of letters in each word
  counts = countOfWords(words);
  //Find the sum of the counts
  total = sum(counts);
  //Divide the sum by the number of words
  return total / count;
}

vector<string> splitByWords(string s) {
  return { };
}
{ "aoeua", "aoeuuee", "oeuoeu" }
vector<int> countOfWords(vector<string> words) {
  int i = 0;
  vector<int> counts {};
  while(i < words.size()) {
    counts.push_back(words[i].length());
    i = i + 1;
  }
  return counts;
}
double sum(vector<double> nums) {
  double sum;
  int i = 0;
  while(i < nums.size()) {
    sum = sum + nums[i];
    i = i + 1;
  }
  return sum;
}
