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
    std::cout << "\nHow many numbers? " << std::endl;
    int n, x;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter the number: ";
        std::cin >> x;
        head = InsertNodeAtBeginning(head, x);
    }
    Print(head);
    
}