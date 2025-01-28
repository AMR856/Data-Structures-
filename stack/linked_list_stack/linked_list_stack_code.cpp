#include "main.h"

using namespace std;
LinkedListStack:: LinkedListStack(){
    size = 0;
}

void LinkedListStack:: push(int data){
    stack.addBeginning(data);
    size++;
}

int LinkedListStack:: pop(){
    if (this->isEmpty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    int temp = stack.getHead()->getData();
    stack.deleteFirst();
    size--;
    return temp;
}

int LinkedListStack:: top(){
    if (this->isEmpty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return stack.getHead()->getData();
}

LinkedListStack:: ~LinkedListStack(){
    size = 0;
}
