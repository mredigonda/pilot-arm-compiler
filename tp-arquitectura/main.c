#include <stdio.h>
#include <assert.h>

#include "main.h"
#include "instruction-decoder.h"

int main(){
    while(true){
        Instruction instr = get_next_instruction();

        instructionType instr_type = get_instruction_type(instr);
        
        switch(instr_type){
			case ASSIGN:
				
				break;
			case INPUT:
				
				break;
			case END:
				
				break;
			case JUMP:
				
				break;
			case LABEL:
				
				break;
			case CONDITIONAL_JUMP:
				
				break;
			default:
				printf("%s\n", INCORRECT_INSTRUCTION);
				return -1;
		}
    }
    return 0;
}
