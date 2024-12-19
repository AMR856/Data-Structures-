#include "main.h"

void DoublyLinkedList:: addNodeLast(int data){
    DoublyLinkedListNode *newNode = new DoublyLinkedListNode(data);
    DoublyLinkedListNode *last = tail;
    newNode->setNext(nullptr);
    size++;
    if (last == nullptr || head == nullptr){
        tail = newNode;
        head = newNode;
        newNode->setPrev(nullptr);
        return;
    }
    newNode->setPrev(last);
    last->setNext(newNode);
    tail = newNode;
}

void DoublyLinkedList:: traverse() {
    if (head == nullptr) std::cout << "Linked list is empty" << std::endl;
    DoublyLinkedListNode* current = head;
    while (current != nullptr){
        std::cout << current->getData() << " "; 
        current = current->getNext();
    }
    std::cout << std::endl;
}

void DoublyLinkedList:: traverseBackward(){
    if (head == nullptr || tail == nullptr) std::cout << "Linked list is empty" << std::endl;
    DoublyLinkedListNode* current = tail;
    while (current != nullptr){
        std::cout << current->getData() << " "; 
        current = current->getPrev();
    }
    std::cout << std::endl;
}

bool DoublyLinkedList:: search(int data){
    if (head == nullptr) std::cout << "Linked list is empty" << std::endl;
    DoublyLinkedListNode* current = head;
    while (current->getData() != data && current->getNext() != nullptr) current = current->getNext();
    if (current->getData() != data && current->getNext() == nullptr) return false;
    return true;
}

void DoublyLinkedList:: addBeginning(int data){
    DoublyLinkedListNode *newNode = new DoublyLinkedListNode(data);
    size++;
    if (head == nullptr || tail == nullptr){
        head = newNode;
        tail = newNode;
        newNode->setPrev(nullptr);
        newNode->setNext(nullptr);
        return;
    }
    newNode->setNext(head);
    newNode->setPrev(nullptr);
    head->setPrev(newNode);
    head = newNode;
}

void DoublyLinkedList:: deleteNode(int data){}
DoublyLinkedList:: ~DoublyLinkedList(){
    DoublyLinkedListNode* current = head;
    while (current != nullptr) {
        DoublyLinkedListNode* temp = current;
        current = current->getNext();
        delete temp;
    }
}
