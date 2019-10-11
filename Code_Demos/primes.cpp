/**
 *
 * Standard Header
 *
 **/

#include <iostream>
#include <cassert>

using namespace std;

/**
 * Function Declarations
 **/

// Checks if a given number is prime
// Input
//   n - The number we are checking for primality
// Output
//   indicates if n is prime
bool isPrime(int n);
void test_isPrime();

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
  test_isPrime();
}

void run() {
  // Variable Declarations

  // Input

  // Output

}


//// Outline
// Look at each number in [2,n)
// Check if it divides into n
// if no number does return true
// otherwise return false

bool isPrime(int n) {
  int i = 1;
  bool p = true;
  // TODO Clean this up!
  if(n <= 1) {
    return false;
  }
  while(i < (n - 1)) {
    i = i+1;
    if (n % i == 0) {
      p = false;
    }
  }
  return p;
}
void test_isPrime() {
  assert(isPrime(2) == true);
  assert(isPrime(4) == false);
  assert(isPrime(-2) == false);
  assert(isPrime(0) == false);
  assert(isPrime(1) == false);
}
