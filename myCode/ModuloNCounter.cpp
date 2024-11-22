/**
 * @file ModuloNCounter.cpp
 * @brief This file contains the implementation of the ModuloNCounter class.
 *
 * The ModuloNCounter class implements a multi-digit counter where each digit
 * is an instance of the ModuloNDigit class. It supports various counter bases
 * and correctly handles overflow between digits.
 *
 * Author: Aman Chauhan
 * @details Master student at HDA (Matriculation No. 1127928)
 */

#include "ModuloNCounter.h"
#include <iostream>
using namespace std;

/**
 * @brief Constructor to initialize the multi-digit counter.
 *
 * Initializes the number of digits for the multi-digit counter and sets the
 * counter base. Each digit is an instance of the ModuloNDigit class,
 * dynamically allocated and initialized with the specified base.
 *
 * @param numDigits The number of digits in the multi-digit counter.
 * @param counterBase The base of counter (Binary, Octal, Decimal, Hexadecimal)
 */
ModuloNCounter::ModuloNCounter(int numDigits, int counterBase) {
    numberDigits = numDigits;
    base = counterBase;

    // Dynamically allocate memory for each digit
    counter = new ModuloNDigit[numberDigits];

    for (int i = 0; i < numberDigits; i++) {
    	// Initialize each digit with the base
        counter[i] = ModuloNDigit(base);
    }
}

/**
 * @brief Destructor to release the dynamically allocated memory.
 *
 * Releases the memory allocated for the digits of the multi-digit counter.
 */
ModuloNCounter::~ModuloNCounter() {
    delete[] counter;  ///< Release memory allocated for the counter digits
}

/**
 * @brief Increment the multi-digit counter with carry over handling.
 *
 * Increments the counter starting from the rightmost digit. If a digit
 * overflows, the carry is propagated to the next left digit. The process stops
 * when there is no carry over or all digits have been processed.
 */
void ModuloNCounter::incrementCounter() {
    bool carry = true;  ///< Set carry flag to true initially

    for (int i = numberDigits - 1; i >= 0 && carry; i--) {
        counter[i].incrementCounter();  ///< Increment the digit
        // If current digit has overflowed, carry increment to the next digit
        if (counter[i].getcurrentCount() != 0) {
            carry = false;  ///< No carry, stop the loop
        }
    }
}

/**
 * @brief Print the name of the multi-digit counter.
 *
 * Prints the type of the counter (e.g., Binary, Decimal, etc.) for the
 * multi-digit counter. It prints the name of the counter only if the
 * number of digits is greater than 0.
 */
void ModuloNCounter::printMultiDigitName(){
   if (numberDigits > 0) {
        counter[0].printModuloName();  ///< Print the counter type name
        cout << endl;  ///< Print a newline after the counter name
   }
}

/**
 * @brief Print the values of each digit in the multi-digit counter.
 *
 * Prints the value of each digit in the multi-digit counter, separated by
 * spaces, on the same line. The values are printed in the order from left
 * to right.
 */
void ModuloNCounter::printMultiDigit() {
    for (int i = 0; i < numberDigits; i++) {
        counter[i].printCounterValue();  ///< Print the value of each digit
    }
    cout << " ";  ///< Space at end of each output line to separate numbers
}

/**
 * @brief Prefix increment operator for ModuloNCounter.
 *
 * This operator increments multi-digit counter and returns updated object.
 * It allows expressions like `++multiDigitCounter` to increment counter and
 * return the updated version.
 *
 * @return ModuloNCounter& Reference to the updated ModuloNCounter object.
 */
ModuloNCounter& ModuloNCounter::operator++() {
    incrementCounter();  // Increment the counter
    return *this;        // Return the updated object
}

/**
 * @brief Postfix increment operator for ModuloNCounter.
 *
 * This operator increments multi-digit counter but returns original object
 * (before the increment). It allows expressions like `multiDigitCounter++` to
 * increment the counter and return the pre-increment version.
 *
 * @param int Unused parameter to differentiate from prefix increment operator.
 * @return ModuloNCounter A copy of the original ModuloNCounter object before
 *         the increment.
 */
ModuloNCounter ModuloNCounter::operator++(int int1) {
    ModuloNCounter temp = *this;  // Make a copy of the current object
    incrementCounter();           // Increment the counter
    return temp;                  // Return the original (pre-increment) object
}
