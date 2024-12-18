#include <iostream>
#include "main.h"

int main(void){
    LinkedList* list1 = new LinkedList();
    list1->addNodeLast(5);
    list1->addNodeLast(3);
    list1->addNodeLast(2);
    list1->traverse();
    std::cout << list1->getSize() << std::endl;
    if (list1->search(2)) std::cout << "found";
    else std::cout << "not found";
    std::cout << std::endl;
    list1->deleteNode(5);
    list1->traverse();
}
