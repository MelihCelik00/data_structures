#include <stdio.h>
#include <stdlib.h>
#include "stack_arr.h"
int size=2;
int head=0;
stack * init(){
    stack * s = (stack *)malloc(sizeof(stack));
    s->queue=NULL;
    s->size=2;
    s->head=0;
    return s;
}
int pop(stack *s){
    if(s->head <= 0 || s->queue==NULL){
        printf(" queue is empty ");
        return -1;
    }
    if(s->head<=s->size/4){
        int *queue2 = (int*)malloc(sizeof(int)*s->size/2);
        for(int i=0;i<s->head;i++)
            queue2[i]=s->queue[i];
        free(s->queue);
        s->queue = queue2;
        s->size /=2;
        
    }
    return s->queue[--s->head];
}
void push(int a, stack *s){
    if(s->queue==NULL){
        s->queue = (int*)malloc(sizeof(int)*2);
    }
    if(s->head>=s->size-1){
        int *queue2 = (int*)malloc(sizeof(int)*s->size*2);
        for(int i=0;i<s->size;i++)
            queue2[i]=s->queue[i];
        free(s->queue);
        s->queue = queue2;
        s->size *=2;
    }
    s->queue[s->head++]=a;
}
void printer(stack *s){
    printf("size: %d ",s->size);
    for(int i=0;i<s->head;i++){
        printf("%d ",s->queue[i]);
    }
}
