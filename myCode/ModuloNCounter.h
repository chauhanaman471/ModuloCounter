/**
 * @file ModuloNCounter.h
 * @brief This file contains the declaration of the ModuloNCounter class.
 *
 * The ModuloNCounter class implements a multi-digit counter, where each digit
 * is an instance of the ModuloNDigit class. It support different counter base
 * (Binary, Octal, Decimal, Hexadecimal) and handles overflow between digits.
 *
 * Author: Aman Chauhan
 * @details Master student at HDA (Matriculation No. 1127928)
 */

#ifndef MODULONCOUNTER_H
#define MODULONCOUNTER_H

#include "ModuloNDigit.h"

/**
 * @class ModuloNCounter
 * @brief A class that implements multi-digit counter with ModuloNDigit objects
 *
 * The ModuloNCounter class models a multi-digit counter, where each digit
 * corresponds to a ModuloNDigit object. It supports various counter bases
 * and handles digit overflow.
 */
class ModuloNCounter {
private:
    int numberDigits;  ///< Number of digits in the multi-digit counter
    int base; ///< Counter base (2, 8, 10, 16)
    ModuloNDigit* counter;  ///< Pointer to array of ModuloNDigit objects

public:
    /**
     * @brief Constructor to initialize the multi-digit counter.
     *
     * Initializes the counter with the specified number of digits and base
     * Each digit is represented by a ModuloNDigit object.
     *
     * @param numDigits The number of digits in the counter.
     * @param counterBase The base of the counter (Binary, Octal, Decimal, etc)
     */
    ModuloNCounter(int numDigits, int counterBase);

    /**
     * @brief Destructor to clean up dynamically allocated memory.
     *
     * Deletes the dynamically allocated array of ModuloNDigit objects.
     */
    ~ModuloNCounter();

    /**
     * @brief Increment the multi-digit counter.
     *
     * Increments the counter, handling carry over if a digit overflows.
     */
    void incrementCounter();

    /**
     * @brief Print the current value of the multi-digit counter.
     *
     * Prints the value of each digit in the multi-digit counter.
     */
    void printMultiDigit();

    /**
     * @brief Print the type of the multi-digit counter (Binary, Decimal, etc)
     *
     * Prints the name of the counter type (e.g., Binary, Decimal, etc.).
     */
    void printMultiDigitName();

    /**
     * @brief Prefix increment operator for ModuloNCounter.
     *
     * This operator increments multi-digit counter and returns updated object.
     * It allows expressions like `++multiDigitCounter` to increment counter
     * and return the updated version.
     *
     * @return ModuloNCounter& Reference to the updated ModuloNCounter object.
     */
    ModuloNCounter& operator++();   ///< For `++multiDigitCounter`

    /**
     * @brief Postfix increment operator for ModuloNCounter.
     *
     * This operator increments multi-digit counter but returns original object
     * (before the increment). It allows expressions like `multiDigitCounter++`
     * to increment the counter and return the pre-increment version.
     *
     * @param int Unused parameter to differentiate from prefix increment
     * @return ModuloNCounter A copy of original ModuloNCounter object before
     *         the increment.
     */
    ModuloNCounter operator++(int); ///< For `multiDigitCounter++`

};

#endif // MODULONCOUNTER_H
