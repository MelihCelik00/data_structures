#include <iostream>

class DoublyLinkedListNode{
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        // DoublyLinkedListNode(int node_data){
        //     this->data = node_data;
        //     this->next = nullptr;
        //     this->prev = nullptr;
        // }
};

DoublyLinkedListNode* GetNewNode(int x){
    DoublyLinkedListNode newNode = new DoublyLinkedListNode();
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

DoublyLinkedListNode* InsertAtHead(DoublyLinkedListNode head, int x){
    DoublyLinkedListNode* newNode = GetNewNode(x);
    if(head == NULL){
        head = newNode;
        return head;
    }
}

int main(){
    Node* head = NULL; // local variable


}