#ifndef stack_arr
#define stack_arr
struct s{
    int size;
    int head;
    int * queue;
};
typedef struct s stack;
stack *init(); 
int pop(stack *);
void push(int,stack *);
void printer(stack*);
#endif
