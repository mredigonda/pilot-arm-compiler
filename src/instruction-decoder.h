/**
 * @file instruction-decoder.h
 * @brief Implements helper functions to read and interpret instructions
 * and expressions.
 */

#ifndef INSTRUCTION_DECODER_H
#define INSTRUCTION_DECODER_H

#include "main.h"

/**
 * @brief Describes all possible instruction types.
 */
typedef enum _instructionType {
    ASSIGN, /**< Assigns the value of an expression to a variable. */
    INPUT, /**< Reads the value of an integer from stdin and writes it to a variable. */
    OUTPUT, /**< Writes the value of an expression to stdout. */
    END, /**< Ends the program. */
    JUMP, /**< Changes the execution point. */
    LABEL, /**< Declares a label. */
    CONDITIONAL_JUMP, /**< Conditionally changes the execution. */
    COMMENT, /**< Not part of the code, just a comment. */
    CALL, /**< Calls a function. */
    FUNCTION, /**< Declares a function. */
    RETURN /**< Returns from a function. */
} instructionType;

/**
 * @brief An instruction is a number describing how many words it has,
 * and that many words.
 */
typedef struct _Instruction {
    int length;
    char **words;
} Instruction;

/**
 * Helper function to get the next line from stdin.
 * @return The next line to read from stdin.
 */
char *          get_instruction_line();

/**
 * Gets an instruction.
 * @return The next instruction to read.
 */
Instruction     get_next_instruction();

/**
 * Determines the type of instruction that an object of type 
 * _Instruction represents.
 * @param instr The instruction whose type you want to know.
 * @return The type of the instruction as an _instructionType.
 */
instructionType get_instruction_type(Instruction instr);

#endif // INSTRUCTION_DECODER_H
