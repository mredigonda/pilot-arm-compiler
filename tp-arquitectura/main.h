/**
 * @file main.h
 * @brief Defines enums and constants used globally.
 */

#ifndef MAIN_H
#define MAIN_H

/**
 * @brief Boolean enum to provide a type similar to bool in C++.
 */
typedef enum _bool {
    false,
    true
} bool;

#define MAX_BUFF_SIZE 256
#define MAX_VARIABLE_NAME_SIZE 15
#define NUMBER_OF_INSTRUCTION_TYPES 10

#define NUMBER_OF_OPERATORS 14
#define OPERATOR_LIST {"+", "-", "*", "/", "&", "|", "^", "<", "<=", "==", ">", ">=", "!=", "!"}

#define INCORRECT_INSTRUCTION "ERROR: One of the instructions is not valid."

#endif // MAIN_H
