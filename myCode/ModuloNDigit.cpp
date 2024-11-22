/**
 * @file ModuloNDigit.cpp
 * @brief Implementation of Modulo N Digit Counter class
 *
 * This file contains the implementation of the ModuloNDigit class, which
 * simulates a counter with a specified base
 * (Binary, Octal, Decimal, or Hexadecimal)
 * It supports incrementing the counter and printing the counter's value in the
 * appropriate format.
 * The counter value wraps around when the maximum count is reached.
 *
 * @author Aman Chauhan
 * @details Master student at Hochschule Darmstadt (Matriculation No. 1127928)
 */

#include "ModuloNDigit.h"
#include <iostream>
using namespace std;

// Default constructor, initializes the counter to 0 with no max count
ModuloNDigit::ModuloNDigit(){
    currentCount = 0;
    maxCount = 0;
    currentOption = NAME;
}

// Constructor initializes the maximum count value based on the counter base
ModuloNDigit::ModuloNDigit(int base) {
    currentOption = NAME;
    currentCount = 0;  // Start the count at 0
    // Set the maxCount based on the input base
    switch (base) {
        case 2: maxCount = 1; break;   // Binary counter (0 to 1)
        case 8: maxCount = 7; break;   // Octal counter (0 to 7)
        case 10: maxCount = 9; break;  // Decimal counter (0 to 9)
        case 16: maxCount = 15; break; // Hexadecimal counter (0 to F)
        default: maxCount = 0; break;  // Invalid base
    }
}

// Increment the counter, wrapping around when the maximum is reached
void ModuloNDigit::incrementCounter() {
    // Increment the current count and wrap around when maxCount is reached
    currentCount = (currentCount + 1) % (maxCount + 1);
}

// Print the name of the modulo counter type (e.g., Binary, Decimal, etc.)
void ModuloNDigit::printModuloName() {
    if(currentOption == NAME){
        // Print the counter name based on the maxCount value
        switch (maxCount) {
            case 1: cout << "Binary counter is generated:"; break;
            case 7: cout << "Octal counter is generated:"; break;
            case 9: cout << "Decimal counter is generated:"; break;
            case 15: cout << "Hexadecimal counter is generated:"; break;
            default: cout << "Invalid counter"; break;
        }
        currentOption = VALUE;
    }
}

// Print the counter value in the appropriate format
void ModuloNDigit::printCounterValue() {
    // Print the counter value depending on the base (binary, octal, etc.)
    switch (maxCount) {
        case 1: // Binary counter (0 or 1)
            cout << (currentCount ? "1 " : "0 ");
            break;
        case 7: // Octal counter (0 to 7)
            cout << " " << oct << currentCount;
            break;
        case 9: // Decimal counter (0 to 9)
            cout << " " << currentCount;
            break;
        case 15: // Hexadecimal counter (0 to F)
            if (currentCount < 10) {
                cout << " " << currentCount;
            } else {
                cout << " " << char(currentCount - 10 + 'A');
            }
            break;
        default:
            // Handle any case that doesn't match 1, 7, 9, or 15
            cout << " Invalid counter value ";
            break;
    }
}

// Getter for the current count value
int ModuloNDigit::getcurrentCount() const {
    return currentCount;
}

/**
 * @brief Prefix increment operator for ModuloNDigit counter.
 *
 * This operator increments the current counter value by one and returns
 * the updated object. It is used in expressions like ++counter.
 *
 * @return ModuloNDigit& Reference to the updated ModuloNDigit object.
 */
ModuloNDigit& ModuloNDigit::operator ++(){
    incrementCounter();  // Increment the counter first
    return *this;        // Return the updated object
}

/**
 * @brief Postfix increment operator for ModuloNDigit counter.
 *
 * This operator increments the current counter value by one but returns
 * the original object (before the increment). It is used in expressions
 * like counter++.
 *
 * @param int1 Unused parameter required for postfix increment signature.
 * @return ModuloNDigit A copy of the original ModuloNDigit object before
 * the increment.
 */
ModuloNDigit ModuloNDigit::operator ++(int int1){
    ModuloNDigit temp = *this;  // Make a copy of the current object
    incrementCounter();         // Increment the counter
    return temp;                // Return the original (pre-increment) object
}

