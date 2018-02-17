#include <stdio.h>
#include <string.h>

#include "expressions.h"
#include "storage.h"
#include "debug.h"

void show_component(Component c){
    if(!c.valid){
        fprintf(stderr, "Not a valid component:\n");
        return;
    }
    if(c.var == true){
        fprintf(stderr, "The component corresponds to the variable %s\n", c.value);
    }
    else {
        fprintf(stderr, "The component consists of the literal: %s\n", c.value);
    }
}

void show_expression(Expression e){
    if(!e.valid){
        fprintf(stderr, "Not a valid expression.\n");
    }
    else {
        if(e.oper != NONE){
            const char *operators[] = OPERATOR_LIST;
            fprintf(stderr, "The expression consists of two components, the operator is: %s\n", operators[e.oper]);
            fprintf(stderr, "Component 1: "); show_component(e.v1);
            fprintf(stderr, "Component 2: "); show_component(e.v2);
        }
        else if(e.oper == NOT){
            fprintf(stderr, "The expression consists of the negation of: "); show_component(e.v1);
        }
        else {
            fprintf(stderr, "The expression consists of just one component\n");
            show_component(e.v1);
        }
    }
}

void show_bucket(Bucket *B){
    fprintf(stderr, "Showing Bucket (%d/%d):\n", B->nelems, B->sz);
    int i;
    for(i = 0; i < B->nelems; i++){
        fprintf(stderr, "%d: %s\n", i, B->storage[i]);
    }
}

void show_instruction(Instruction instr){
    int n = instr.length, i;
    fprintf(stderr, "The instruction consists of %d words.\n", n);
    for(i = 0; i < n; i++){
        fprintf(stderr, "sz(%d) -> %s\n", (int)strlen(instr.words[i]), instr.words[i]);
    }
}
