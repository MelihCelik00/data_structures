#include <stdio.h>
#include <stdlib.h>
struct n{
    int x;
    struct n * next;
};
typedef struct n node;

void printer(node * r){
    while(r!=NULL){
        printf("%d ",r->x);
        r = r->next;
    }
    printf("\n");
} 

void addNode(node * r, int x){
    while (r->next != NULL){
        r = r->next;
    }
    r->next = (node *)malloc(sizeof(node));
    r->next->x = x;
    r->next->next = NULL;
}
node * addSorted(node * r,int x){
    if(r==NULL){ // If linked list is empty;
        r =(node *)malloc(sizeof(node));
        r->next = NULL;
        r->x = x;
        return r;
    }
    // If linked list is not empty;
    if(r->x > x){ // If x is smaller than first value of root
        node * temp = (node *)malloc(sizeof(node));
        //temp -> next = NULL;
        temp -> x = x; 
        temp -> next = r;
        r = temp;
        return temp;
    }
    node * iter = r;
    while(iter-> next != NULL && iter->next-> x < x){
        iter = iter->next;
    }
    
    node * temp = (node *)malloc(sizeof(node));
    temp -> next = iter ->next;
    iter -> next = temp;
    temp -> x = x;
    return r;

}

node * deleteNode(node * r, int x){
    node * temp;
    node * iter = r;
    if(r->x == x){
        temp = r;
        r = r->next;
        free(temp);
        return r;
    }
    while(iter->next != NULL && iter->next->x != x){
        iter = iter->next;
    }
    if(iter -> next == NULL){
        printf("Value not found!\n");
        return r;
    }
    temp = iter->next;
    iter->next = iter->next->next;
    free(temp);
    return r;
}

int main(){
    node * root;
    root = NULL;
    root = addSorted(root,400);
    root = addSorted(root,40);
    root = addSorted(root,4);
    root = addSorted(root,450);
    root = addSorted(root,50);
    printer(root);
    root = deleteNode(root,50);
    printer(root);
    printf("New operations:\n");
    root = deleteNode(root,999);
    printer(root);
    root = deleteNode(root,4);
    printer(root);
    root = deleteNode(root,450);
    printer(root);
    
    printer(root);
    node * iter = root;
    for(int i=0;i<3;i++)
        iter = iter -> next;
    node * temp = (node *)malloc(sizeof(node));
    temp -> next = iter ->next;
    iter -> next = temp;
    temp -> x = 100;
    printer(root);
}