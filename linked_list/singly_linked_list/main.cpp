#include <iostream>
#include <thread>
#include <chrono>
#include "main.h"

int main(void){
    srand(time(0));
    AbstractLinkedList* list1 = new SinglyLinkedList();
    list1->addNodeLast(5);
    list1->addNodeLast(3);
    list1->addNodeLast(2);
    list1->traverse();
    std::cout << list1->getSize() << std::endl;
    if (list1->search(2)) std::cout << "Found";
    else std::cout << "Not Found";
    std::cout << std::endl;
    // list1->deleteNode(5);
    list1->deleteFirst();
    list1->deleteEnd();
    list1->traverse();
    std::cout << "-------------------" << std::endl;
    DoublyLinkedList* list2 = new DoublyLinkedList();
    list2->addNodeLast(5);
    list2->addNodeLast(3);
    list2->addNodeLast(2);
    list2->traverse();
    std::cout << list2->getSize() << std::endl;
    if (list2->search(2)) std::cout << "Found";
    else std::cout << "Not Found";
    std::cout << std::endl;
    // list2->deleteNode(5);
    list2->deleteFirst();
    list2->deleteEnd();
    list2->traverseBackward();
    RandomFactory *factory = new RandomFactory();
    AbstractLinkedList *randomList1 = factory->getList();
    std::cout << "Class name 1: " << typeid(*randomList1).name() << std::endl;
    AbstractLinkedList *randomList2 = factory->getList();
    std::cout << "Class name 2: " << typeid(*randomList2).name() << std::endl;
}
