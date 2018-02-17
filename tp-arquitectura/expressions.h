/**
 * @file expressions.h
 * @brief Implements functions to recognize valid name of variables,
 * and to read expressions and components.
 */
#ifndef EXPRESSIONS_H
#define EXPRESSIONS_H

#include "main.h"
#include "instruction-decoder.h"

/**
 * @brief Represents a component. If it is valid, then is either a 
 * value or a variable. The value is stored in 'value' and 'var' 
 * indicates if it is a variable or a literal.
 */
typedef struct _Component {
    bool valid, var;
    char* value;
} Component;

/**
 * @brief Describes all possible operator names (in Spanish, sorry).
 */
typedef enum _operatorType {
    SUMA,
    RESTA, 
    MULTIPLICACION,
    DIVISION,
    AND,
    OR,
    XOR,
    MENOR,
    MENOR_O_IGUAL,
    IGUAL,
    MAYOR,
    MAYOR_O_IGUAL,
    DISTINTO,
    NOT,
    NONE
} operatorType;

/**
 * @brief Represents an expression. An expression is a unique component,
 * or a 'not' operation followed by a single component, or other type
 * of operator, followed by two components.
 */
typedef struct _Expression {
    bool valid;
    operatorType oper;
    Component v1, v2;
} Expression;

/**
 * @param s The string that we want to know if it represents a valid
 * integer.
 * @return Returns true if the string is a valid integer.
 */
bool            is_valid_integer(const char *s);

/**
 * @param s The string that we want to know if it represents a label 
 * number.
 * @return Returns true if the string corresponds to a label number. A
 * label number is an integer value between 0 and 2^31 - 1, no leading
 * zeroes allowed, no -0 allowed.
 */
bool            is_label_number(const char *s);

/**
 * @param s The string that we want to know if it represents a valid
 * variable name.
 * @return Returns true if the string corresponds to a valid variable
 * name: a lowercase english letter, followed by a label number.
 */
bool            is_valid_variable_name(const char *s);

/**
 * Helper function used to determine which operator a string is, in
 * case it is an operator.
 * @param word The word that we want to know which operator it 
 * represents.
 * @return The operator that the word represents, or NONE if it
 * doesn't represent any operator.
 */
operatorType    get_operator_type(const char *word);

/**
 * Extracts a component from a string.
 * @param s The string from which to extract the component.
 * @return Returns a component that represents the string.
 */
Component       get_component(const char *s);

/**
 * Reads an expression from a list of words (an instruction), at some
 * position.
 * @param instr The instruction from which to read the expression.
 * @param pos The position in the instruction from which to read
 * the expression.
 * @return Returns an expression. In case something fails, returns that
 * the expression is not valid.
 */
Expression      get_next_expression(Instruction instr, int pos);

#endif // EXPRESSIONS_H
