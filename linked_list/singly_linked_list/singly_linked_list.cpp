#include "main.h"

void SinglyLinkedList:: addNodeLast(int data){
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        SinglyLinkedListNode* current = head;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(newNode);
    }
    size++;
}

void SinglyLinkedList:: traverse() {
    if (head == nullptr) std::cout << "Linked list is empty" << std::endl;
    SinglyLinkedListNode* current = head;
    while (current != nullptr){
        std::cout << current->getData() << " "; 
        current = current->getNext();
    }
    std::cout << std::endl;
}

void SinglyLinkedList:: addBeginning(int data) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    newNode->setNext(head);
    head = newNode;
}

bool SinglyLinkedList:: search(int data){
    if (head == nullptr) std::cout << "Linked list is empty" << std::endl;
    SinglyLinkedListNode* current = head;
    while (current->getData() != data && current->getNext() != nullptr) current = current->getNext();
    if (current->getData() != data && current->getNext() == nullptr) return false;
    return true;
}

void SinglyLinkedList:: deleteNode(int data){
    if (head == nullptr) {
        std::cout << "List is empty. Cannot delete.\n";
        return;
    }
    if (head->getData() == data) {
        SinglyLinkedListNode* temp = head;
        head = head->getNext();
        delete temp;
        size--;
        return;
    }
    SinglyLinkedListNode* current = head;
    while (current->getNext() != nullptr && current->getNext()->getData() != data) {
        current = current->getNext();
    }
    if (current->getNext() == nullptr) { 
        std::cout << "Node with data " << data << " not found.\n";
        return;
    }
    SinglyLinkedListNode* temp = current->getNext();
    current->setNext(temp->getNext());
    delete temp;
    size--;
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

void SinglyLinkedList:: deleteEnd(){
    if (head == nullptr){
        std::cout << "The linked list is empty" << std::endl;
        return;
    }
    SinglyLinkedListNode *current = head;
    while (current->getNext()->getNext() != nullptr) current = current->getNext();
    SinglyLinkedListNode *temp = current->getNext();
    current->setNext(nullptr);
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
