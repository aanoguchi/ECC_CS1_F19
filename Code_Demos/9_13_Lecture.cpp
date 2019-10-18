/* Week 3 Lecture and Demo.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    double n = 2.14;
    char answer = 'n';
    // examples of initializng boolean values
    bool b = true;
    bool c = true;

    int student = 0;

    // Used for random number generation
    unsigned seed = time(0);
    srand(seed);
    // OR! `srand(time(0));`
    cout << (rand() % 22) + 1 << endl;

    cout << "Would you like the value as a whole number? ";
    cin >> answer;

    if('y' == answer) {
        cout << static_cast<int>(n) << endl;
    } else if('n' == answer) {
        cout << n << endl;
    } else {
        cout << "please enter either a 'y' or 'n'." << endl;
    }
    return 0;
}