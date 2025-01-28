#ifndef MAIN_H
#define MAIN_H

#include <iostream>

class AbstractStack {
    protected:
        int size;
        int capacity;
    public:
        virtual void push(int data) = 0;
        int stackSize(){return size;}
        virtual int pop() = 0;
        virtual int top() = 0;
        virtual ~AbstractStack(){}
};

class ArrayStack : public AbstractStack{
    private:
        int* stackArray;
        int arrayTop;
    public:
        ArrayStack(int size);
        void push(int data) override;
        int pop() override;
        int top() override;
        ~ArrayStack();
};

#endif
