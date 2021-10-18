#include <iostream>

struct Node 
{    
    int data;
    Node *link;
};

void printNode(Node* r)
{
    while (r!=NULL)
    {
        std::cout << r->data << std::endl;
        r = r->link;
    }
}



int main()
{
    Node* head; // global variable, can be accessed anywhere

    head = NULL;
    Node* temp = new Node();

    temp -> data = 2;
    temp -> link = NULL;

    head = temp;

    temp = new Node();
    temp -> data = 4;
    temp -> link = NULL;

    Node* temp1 = head;
    while(temp1 -> link != NULL)
    {
        temp1= temp1->link;
        std::cout << "temp1: " << temp1 << std::endl; 
    }
    temp1->link = temp;
    //printer(head)
}