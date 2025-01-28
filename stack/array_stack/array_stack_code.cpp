#include "main.h"
#include <iostream>

using namespace std;

ArrayStack::ArrayStack(int capacity) {
    this->capacity = capacity;
    stackArray = new int[capacity];
    size = 0;
    arrayTop = -1;
}

void ArrayStack::push(int data) {
    if (size == capacity) {
        cout << "Stack is full" << endl;
        return;
    }
    stackArray[++arrayTop] = data;
    size++;
}

int ArrayStack::pop() {
    if (arrayTop == -1) {
        cout << "Stack is Empty" << endl;
        return -1;
    }
    int temp = stackArray[arrayTop--];
    size--;
    return temp;
}

int ArrayStack::top() {
    if (arrayTop == -1) {
        cout << "Stack is Empty" << endl;
        return -1;
    }
    return stackArray[arrayTop];
}

ArrayStack::~ArrayStack() {
    delete[] stackArray;
    stackArray = nullptr;
    size = 0;
    arrayTop = -1;
}
