# Modulo N Counter Simulation

## Description

This project simulates Modulo N counters with customizable base (binary, octal, decimal, hexadecimal) and number of digits. It supports both single-digit and multi-digit counters and demonstrates the functionality of prefix and postfix increments.

## Features
- Simulate counters with bases: 2, 8, 10, and 16.
- Supports both single-digit and multi-digit counters.
- Demonstrates prefix and postfix increment functionality.
- Prints the counter values in the specified base format.

## Classes
### `ModuloNDigit`
- Simulates a single digit counter.
- Supports binary, octal, decimal, and hexadecimal bases.
- Handles wraparound when the maximum count is reached.

### `ModuloNCounter`
- Simulates a multi-digit counter.
- Each digit is an instance of `ModuloNDigit`.
- Handles carryover between digits when overflow occurs.

## Files
- **main.cpp**: Contains the main program that takes user input and runs the simulation.
- **ModuloNDigit.h**: Header file for the `ModuloNDigit` class, which defines a single digit modulo counter.
- **ModuloNDigit.cpp**: Implementation of the `ModuloNDigit` class.
- **ModuloNCounter.h**: Header file for the `ModuloNCounter` class, which defines a multi-digit modulo counter.
- **ModuloNCounter.cpp**: Implementation of the `ModuloNCounter` class.

## Author
Aman Chauhan  
Master's Student at Hochschule Darmstadt (Matriculation No. 1127928)

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

