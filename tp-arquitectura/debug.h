/**
 * @file debug.h
 * @brief Implements utilities to print values to make the process
 * of development easier.
 */

#ifndef DEBUG_H
#define DEBUG_H

#include "storage.h"
#include "expressions.h"
#include "instruction-decoder.h"

/**
 * Given a component, prints all information about it to the screen.
 */
void show_component(Component c);

/**
 * Given an expression, prints all information about it to the screen.
 */
void show_expression(Expression e);

/**
 * Given a bucket, prints its capacity and its elements along with
 * their positions in the bucket.
 */
void show_bucket(Bucket *B);

/**
 * Given an instruction, prints the number of words in it, and prints
 * each word of the instruction in a new line.
 */
void show_instruction(Instruction instr);

#endif // DEBUG_H
