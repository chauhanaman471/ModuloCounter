/**
 * @file main.cpp
 * @brief Main program for creating and simulating Modulo N counters
 *
 * This program allows the user to create a single/multi-digit modulo counter
 * with bases 2, 8, 10, or 16. It increments the counter 20 times and prints
 * results using both prefix and postfix increments. The user inputs the number
 * of digits and the base of the counter.
 *
 * @author Aman Chauhan
 * @details Master student at Hochschule Darmstadt (Matriculation No. 1127928)
 */

#include <iostream>
#include "ModuloNDigit.h"
#include "ModuloNCounter.h"
using namespace std;

int main() {
    int numOfDigits, counterBase;

    // Request user input for counter parameters
    cout << "Please enter the parameters of your counter:" << endl;

    // Input number of digits for the counter
    cout << "Number of digits: ";
    cin >> numOfDigits;
    while (numOfDigits < 1) {
        cout << "Please enter a valid number of digits: ";
        cin >> numOfDigits;
    }

    // Input the base for the counter (2, 8, 10, or 16)
    cout << "Enter the counter base (2/8/10/16): ";
    cin >> counterBase;
    while (counterBase != 2 && counterBase != 8 && counterBase != 10 &&
           counterBase != 16) {
        cout << "Please enter a valid base (2, 8, 10, 16): ";
        cin >> counterBase;
    }

    // Handle single-digit counter (numOfDigits = 1)
    if (numOfDigits == 1) {
        ModuloNDigit counter{counterBase};  // Create a single digit counter
        counter.printModuloName();          // Print name of the counter type

        // Show prefix increment
        cout << "\nPrefix Increment for Single-Digit Counter:" << endl;
        for (int i = 0; i < 20; i++) {
            counter.printCounterValue();    // Print current counter value
            ++counter;                      // Prefix increment
            //counter++;					// Use for Postfix increment
        }
        cout << endl;

    } else {
        // Handle multi-digit counter (numOfDigits > 1)
        ModuloNCounter multiDigitCounter{numOfDigits, counterBase};
        // Create multi-digit counter instance
        multiDigitCounter.printMultiDigitName();  // Print the counter type

        // Show prefix increment
        cout << "\nPrefix Increment for Multi-Digit Counter:" << endl;
        for (int i = 0; i < 20; i++) {
            multiDigitCounter.printMultiDigit(); // Print current counter value
            ++multiDigitCounter;                 // Prefix increment
            //multiDigitCounter++;				 // Use for Postfix increment
        }
        cout << endl;

    }

    return 0;
}
