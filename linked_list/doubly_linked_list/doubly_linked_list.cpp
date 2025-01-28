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
    newNode->setPrev(nullptr);
    size++;
    if (head == nullptr || tail == nullptr){
        head = newNode;
        tail = newNode;
        newNode->setNext(nullptr);
        return;
    }
    newNode->setNext(head);
    head->setPrev(newNode);
    head = newNode;
}

void DoublyLinkedList:: deleteEnd(){
    if (head == nullptr || tail == nullptr){
        std::cout << "The linked list is empty" << std::endl;
        return;
    }
    DoublyLinkedListNode *temp = tail;
    temp->getPrev()->setNext(nullptr);
    tail = temp->getPrev();
    delete temp;
    size--;
}

void DoublyLinkedList:: deleteFirst(){
    if (head == nullptr || tail == nullptr){
        std::cout << "The linked list is empty" << std::endl;
        return;
    }
    DoublyLinkedListNode* temp = head;
    temp->getNext()->setPrev(nullptr);
    head = temp->getNext();
    delete temp;
    size--;
}

void DoublyLinkedList:: deleteNode(int data){
    if (head == nullptr) {
        std::cout << "List is empty. Cannot delete.\n";
        return;
    }
    if (head->getData() == data) {
        DoublyLinkedListNode* temp = head;
        head = head->getNext();
        head->setPrev(nullptr);
        delete temp;
        size--;
        return;
    }
    DoublyLinkedListNode* current = head;
    while (current->getNext() != nullptr && current->getNext()->getData() != data) {
        current = current->getNext();
    }
    if (current->getNext() == nullptr) { 
        std::cout << "Node with data " << data << " not found.\n";
        return;
    }
    DoublyLinkedListNode* temp = current->getNext();
    current->setNext(temp->getNext());
    current->getNext()->setPrev(current);
    delete temp;
    size--;
}

DoublyLinkedList:: ~DoublyLinkedList(){
    DoublyLinkedListNode* current = head;
    while (current != nullptr) {
        DoublyLinkedListNode* temp = current;
        current = current->getNext();
        delete temp;
    }
}
