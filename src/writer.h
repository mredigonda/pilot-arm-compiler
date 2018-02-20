/**
 * @file writer.h
 * @brief Consists of all the functions to print the ARM program. No
 * other file is allowed to print to stdout.
 */
#ifndef WRITER_H
#define WRITER_H

#include "expressions.h"
#include "storage.h"

/**
 * Writes the evaluation of a component, leaving its value stored in 
 * the register indicated by the parameter where.
 * @param v Component to evaluate.
 * @param B Bucket with the names of the variables.
 * @param where Indicates where to store the value of the component.
 */
void evaluate_component(Component v, Bucket *B, int where);

/**
 * Writes the evaluation of an expression, leaving its value stored in
 * r1.
 * @param e The expression to evaluate.
 * @param B Bucket with the names of the variables. May be modified
 * will newly read variable names in the expression.
 */
void evaluate_expression(Expression e, Bucket *B);

/**
 * Writes the printing of the value stored in r1. Assumes that the 
 * instruction push {ip, lr} was used before, and that pop {ip, pc}
 * will be used at the end. 
 */
void print_value();

/**
 * Writes a reading of a value from stdin and loads that value into the
 * universe array.
 * @param B Bucket with the names of the variables.
 * @param s Name of the variable that is assigned the value read.
 */
void scan_value(Bucket *B, const char *s);

/**
 * Writes the load of the value stored in r1 to a variable.
 * @param B Bucket with the names of the variables.
 * @param s Name of the variable that is assigned the value of r1.
 */
void load_value(Bucket *B, const char *s);

/**
 * Writes definition of a label in the program.
 * @param l Label number.
 */
void mark_label(const char *l);

/**
 * Writes a jump to a label in the program. 
 * @param l Label number, that indicates where to jump.
 */
void jump_label(const char *l);

/**
 * Writes a conditional jump, that jumps just in the case that the
 * value stored in r1 is not zero.
 * @param l Label number, that indicates where to jump.
 */
void conditional_jump(const char *l);

/**
 * Writes the instruction to leave the program.
 */
void exit_program();

/**
 * Writes the call of a function in ARM.
 * @param name Name of the function to call.
 */
void write_call(const char *name);

/**
 * Writes the declaration of a function in ARM.
 * @param name Name of the function to declare.
 */
void declare_function(const char *name);

/**
 * Writes the return of a function in ARM.
 * @param name Name of the function from which to return.
 */
void return_function(const char *name);

/**
 * Writes all needed code to initialize the ARM program.
 */
void initialize();

/**
 * Writes all needed code at the end of the ARM program.
 */
void terminate(Bucket *B);

#endif // WRITTER_H
