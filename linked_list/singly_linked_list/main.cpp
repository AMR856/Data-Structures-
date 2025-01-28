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
}
