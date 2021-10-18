#include <iostream>

class Node 
{
    public:
        int data;
        Node* next;
};

//Node* head; // global variable, can be accessed anywhere
Node* InsertNodeAtBeginning(Node* head,int x)
{
    Node* temp = new Node();
    temp -> data = x;
    temp -> next = NULL;
    if (head != NULL) temp -> next = head;
    head = temp;
    return head;
}

Node* InsertNodeAtNthPosition(Node* head, int data, int n)
{
    Node* temp1 = new Node();
    temp1 -> data = data;
    temp1 -> next = NULL;
    if (n==1) {
        temp1->next = head;
        head = temp1;
        return head;
    }
    Node* temp2 = head;
    for (int i = 0; i < n-2; i++)
    {
        temp2  = temp2 -> next;
    }
    temp1 -> next = temp2 -> next;
    temp2 -> next = temp1;
    
    
    
}

void Print(Node* head)
{
    //Node* temp = head; // if printing a global variable, a new declaration must be done here to prevent ruining the global variable
    std::cout << "The list is: ";
    while (head != NULL)
    {
        std::cout << head->data << " ";
        head = head -> next;
    }
    std::cout << "\n";
}

int main()
{
    Node* head = NULL; // local variable, must be passed as referance
    InsertNodeAtNthPosition(head, 2, 1); // List: 2
    InsertNodeAtNthPosition(head, 3, 2); // List: 2, 3
    InsertNodeAtNthPosition(head, 4, 1); // List: 4, 2, 3
    InsertNodeAtNthPosition(head, 5, 2); // List: 4, 5, 2, 3
    /*std::cout << "\nHow many numbers? " << std::endl;
    int n, x;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter the number: ";
        std::cin >> x;
        head = InsertNodeAtBeginning(head, x);
    }*/
    Print(head);
    
}