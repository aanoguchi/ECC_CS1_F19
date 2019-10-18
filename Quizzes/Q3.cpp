/*
 * Quiz 3
 * Write a program which asks the user for 5 numbers,
 * then calculates and outputs the average of those numbers.
 * 
 */
#include <iostream>

using namespace std;

int main() {
    // Initialize variables
    int a,b,c,d,e,sum;
    double average;
    // Ask user for 5 numbers
    cout << "Please enter 5 numbers separated by whitespace: ";
    // Store numbers as variables
    cin >> a >> b >> c >> d >> e;
    // Calculate average
        // Find sum of numbers
    sum = a + b + c + d + e;
        // Divide by 5
        // Store the average
    average = sum / 5;
    // Display the average
    cout << "The average of " 
         << a << ", " 
         << b << ", "
         << c << ", "
         << d << ", and "
         << e << " is "
         << average << endl; 
    return 0;
}