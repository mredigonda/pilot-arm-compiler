#ifndef DEBUG_H
#define DEBUG_H

#include "storage.h"
#include "expressions.h"

/**
 * Dada una componente, imprime por pantalla toda la informacion sobre
 * ella.
 */
void show_component(Component c);

/**
 * Dada una expresion, imprime por pantalla toda la informacion sobre
 * ella.
 */
void show_expression(Expression e);

void show_bucket(Bucket *B);

#endif // DEBUG_H
