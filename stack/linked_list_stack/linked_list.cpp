#include "main.h"

void SinglyLinkedList:: addBeginning(int data) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    newNode->setNext(head);
    head = newNode;
}

void SinglyLinkedList:: deleteFirst(){
    if (head == nullptr){
        std::cout << "The linked list is empty" << std::endl;
        return;
    }
    SinglyLinkedListNode *temp = head;
    head = head->getNext();
    delete temp;
    size--;
}

SinglyLinkedList:: ~SinglyLinkedList(){
    SinglyLinkedListNode* current = head;
    while (current != nullptr) {
        SinglyLinkedListNode* temp = current;
        current = current->getNext();
        delete temp;
    }
}
