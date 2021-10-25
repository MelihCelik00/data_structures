#include <iostream>

class DoublyLinkedListNode{
    public:
        int data; // [prev][data][next]
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        // DoublyLinkedListNode(int node_data){
        //     this->data = node_data;
        //     this->next = nullptr;
        //     this->prev = nullptr;
        // }
};

DoublyLinkedListNode* GetNewNode(int x){
    DoublyLinkedListNode * newNode = new DoublyLinkedListNode();
    newNode->data = x;
    newNode->prev = NULL; 
    newNode->next = NULL;
    return newNode; 
}

DoublyLinkedListNode* InsertAtHead(DoublyLinkedListNode* head, int x){
    DoublyLinkedListNode* newNode = GetNewNode(x); 
    if(head == NULL){
        head = newNode;
        return head;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    return head;
}

void Print(DoublyLinkedListNode* head){
    DoublyLinkedListNode* temp = head;
    std::cout << "Print forward: ";
    while(temp != NULL){
        std::cout << temp -> data << " ";
        temp = temp -> next;
    }
    std::cout << std::endl;
}

void ReversePrint(DoublyLinkedListNode* head){
    DoublyLinkedListNode* temp = head;
    if(temp == NULL) return; // if list is empty, just exit
    // Going last node
    while(temp -> next != NULL){
        temp = temp->next;
    }
    // Traversing backward using prev pointer
    std::cout << "Print backward: ";
    while(temp != NULL){
        std::cout << temp->data << " ";
        temp = temp -> prev;
    }
    std::cout << std::endl;

}

int main(){
    DoublyLinkedListNode* head = NULL; // local variable

    head = InsertAtHead(head, 2);
    Print(head);
    ReversePrint(head);
    head = InsertAtHead(head, 4);
    Print(head);
    ReversePrint(head);
    head = InsertAtHead(head, 6);
    Print(head);
    ReversePrint(head);

}