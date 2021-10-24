#include <iostream>

class Node 
{
    public:
        int data;
        Node* next;
};
/* class with a constructor
class Node {
    public:
        int data;
        Node* next;

        Node(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};
*/
//Node* head; // global variable, can be accessed anywhere
Node* InsertNodeAtBeginning(Node* head,int x) // defined return type, trying different implementations
{
    Node* temp = new Node();
    temp -> data = x;
    temp -> next = NULL;
    if (head != NULL) temp -> next = head; // if root is not null, connect head node as new node's link
    head = temp;
    return head;
}

Node* InsertNodeAtNthPosition(Node* head, int data, int n)
{
    Node* temp1 = new Node();
    temp1 -> data = data;
    temp1 -> next = NULL;
    if (n==1) { // Special Case(1st Position): implementation is like InsertNodeAtBeginning method
        temp1->next = head;
        head = temp1;
        return head;
    }
    Node* temp2 = head;
    for (int i = 0; i < n-2; i++){
        temp2  = temp2 -> next;
    }
    temp1 -> next = temp2 -> next;
    temp2 -> next = temp1;
    return head;
}

Node* InsertNodeAtTheEnd(Node* head, int data)
{
    Node* temp1 = new Node(); // define temporary node as usual
    temp1 -> data = data;
    temp1 -> next = NULL;
    if (head == NULL) head = temp1; // if there is no such linked list
    if (head != NULL){
        Node* temp2 = head;
        while (temp2->next != NULL){
            temp2 = temp2 -> next;
        }
        temp2 -> next = temp1;
    }
    return head;
}

Node* DeleteNode(Node* head,int n) // Delete node at position n
{
    Node* temp1 = head;
    if (n==1){ // special case if first node wanted to be deleted
        head = temp1->next; // head now points the second node
        free(temp1);
        return head;
    }
    
    int i;
    for (int i = 0; i < n-2; i++) temp1 = temp1->next; //temp1 points the (n-1)th node
    
    Node* temp2 = temp1 -> next; // nth node
    temp1->next = temp2 -> next; // (n+1)th node
    free(temp2); // delete temp2
    return head;
}

Node* ReverseNode(Node* head){ // Iterative method
    Node *prev, *current, *next;
    current = head;
    prev = NULL; // prev node is a must while using iterative method
    while (current != NULL)
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    free(current);
    free(next);
    return head;
}

void Print(Node* head)
{
    Node* temp = head; // if printing a global variable, a new declaration must be done here to prevent ruining the global variable
    std::cout << "The list is: ";
    while (temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp -> next;
    }
    std::cout << "\n";
}

void PrintByRecursion(Node* r){
    if (r == NULL){
        std::cout << "\n";
        return;
    }
    std::cout << r->data << " ";
    PrintByRecursion(r->next); 
}

void PrintReverseByRecursion(Node* r){
    if (r == NULL) return;
    PrintReverseByRecursion(r->next); 
    std::cout << r->data << " ";
}

int main()
{
    Node * head = NULL; // if root is defined as local variable, must be passed as referance to the related functions
    head = InsertNodeAtNthPosition(head, 2, 1); // List: 2
    Print(head);
    head = InsertNodeAtNthPosition(head, 4, 2); // List: 2, 4
    head = InsertNodeAtBeginning(head, 1);
    head = InsertNodeAtTheEnd(head, 6);
    head = InsertNodeAtTheEnd(head, 5); // List: 1, 2, 4, 6, 5
    Print(head);
    int n;
    std::cout << "Enter a position: ";
    std::cin >> n;
    head = DeleteNode(head, n);
    Print(head);
    head = ReverseNode(head);
    Print(head);

    PrintByRecursion(head);
    PrintReverseByRecursion(head);
}