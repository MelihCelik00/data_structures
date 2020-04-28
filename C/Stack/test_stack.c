#include <stdio.h>
#include <stdlib.h>
#include "stack_arr.h"
// Compile test_stack.c and stackArray.c together!
int main(){
    struct stack *s1 = init();
    struct stack *s2 = init();
    for (int i = 0; i < 10; i++){
        push(i*10,s1);
    }
    printer(s1);
    for (int i = 0; i < 10; i++){
        push(pop(s1),s2);
    }
    printer(s1);
    printer(s2);
}
