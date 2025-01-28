#include <iostream>
#include <thread>
#include <chrono>
#include "main.h"

int main(void){
    srand(time(0));
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
}
