/**
 * @file ModuloNDigit.h
 * @brief Header file for Modulo N Digit Counter class
 *
 * This header defines the ModuloNDigit class, which simulates a counter with
 * a specified base (Binary, Octal, Decimal, or Hexadecimal). The class support
 * incrementing the counter, printing the counter's value in the appropriate
 * format, and printing the counter's type (binary, octal, etc.).
 *
 * @author Aman Chauhan
 * @details Master student at Hochschule Darmstadt (Matriculation No. 1127928)
 */

#ifndef MODULONDIGIT_H
#define MODULONDIGIT_H

/**
 * @class ModuloNDigit
 * @brief Class to implement a modulo N digit counter with specified base.
 *
 * This class simulates a counter with a specified base (Binary, Octal,
 * Decimal, or Hexadecimal) and provides methods to increment the counter
 * and print its value and type.
 */
class ModuloNDigit {
private:
    /**
     * @enum CounterOutput
     * @brief Enum to decide whether to print the name or value of counter.
     */
    enum CounterOutput {
        NAME,  ///< To print the name of counter type (e.g.Binary, Decimal)
        VALUE  ///< To print the current value of the counter
    };

    CounterOutput currentOption; ///< Current option to print name or value
    int currentCount;            ///< Variable to store the current count
    int maxCount;                ///< Variable to store the maximum count value

public:
    /**
     * @brief Default constructor to initialize the counter.
     *
     * Initializes the current count to 0 and sets the maxCount to 0. The
     * current option is set to print the name of the counter.
     */
    ModuloNDigit();

    /**
     * @brief Parameterized constructor to initialize the counter with base.
     *
     * Initializes the current count to 0 and sets the maxCount depending on
     * the input base
     * (2 for Binary, 8 for Octal, 10 for Decimal, 16 for Hexadecimal).
     *
     * @param base The base for the counter (2, 8, 10, or 16).
     */
    ModuloNDigit(int base);

    /**
     * @brief Increment counter value and wrap around when maxCount is reached.
     *
     * This method increments the current count, and if the count exceeds the
     * maximum count, it wraps around to 0.
     */
    void incrementCounter();

    /**
     * @brief Print the name of the counter type (e.g., Binary, Decimal).
     *
     * Prints the type of counter (e.g., "Binary counter is generated:").
     */
    void printModuloName();

    /**
     * @brief Print the current value of the counter.
     *
     * Prints the current count value in the appropriate format based on the
     * counter's base (Binary, Octal, Decimal, Hexadecimal).
     */
    void printCounterValue();

    /**
     * @brief Get the current count value.
     *
     * Returns the current count value.
     *
     * @return The current count value.
     */
    int getcurrentCount() const;

    /**
     * @brief Prefix increment operator for ModuloNDigit counter.
     *
     * This operator increments the counter and returns the updated object.
     * It is used in expressions like `++counter`.
     *
     * @return ModuloNDigit& Reference to the updated ModuloNDigit object.
     */
    ModuloNDigit& operator++();  // For ++counter

    /**
     * @brief Postfix increment operator for ModuloNDigit counter.
     *
     * This operator increments the counter but returns the original object
     * (before the increment). It is used in expressions like `counter++`.
     *
     * @param int Unused parameter to differentiate postfix from prefix
     * @return ModuloNDigit A copy of the original ModuloNDigit object before
     * the increment.
     */
    ModuloNDigit operator++(int); // For counter++


};

#endif // MODULONDIGIT_H
