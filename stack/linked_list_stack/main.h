#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <math.h>

class SinglyLinkedListNode {
private:
    int data;
    SinglyLinkedListNode* next;
public:
    SinglyLinkedListNode(int data) : data(data), next(nullptr){}
    SinglyLinkedListNode(int data, SinglyLinkedListNode *next): data(data), next(next){}
    ~SinglyLinkedListNode() {}
    int getData() const {return data;}
    void setData(int d) {data = d;}
    SinglyLinkedListNode* getNext() const {return next;}
    void setNext(SinglyLinkedListNode* nextNode) {next = nextNode;}
};

class AbstractLinkedList {
protected:
    int size;
public:
    virtual void addBeginning(int data) = 0;
    virtual void deleteFirst() = 0;
    virtual ~AbstractLinkedList() {}
};

class SinglyLinkedList : public AbstractLinkedList {
private:
    SinglyLinkedListNode *head;
public:
    void addBeginning(int data);
    SinglyLinkedListNode *getHead(){return head;}
    void deleteFirst();
    ~SinglyLinkedList();
};

class AbstractStack {
    protected:
        int size;
    public:
        virtual void push(int data) = 0;
        int stackSize(){return size;}
        bool isEmpty(){return size == 0;}
        virtual int pop() = 0;
        virtual int top() = 0;
        ~AbstractStack(){}
};

class LinkedListStack : public AbstractStack{
    private:
        SinglyLinkedList stack;
    public:
        LinkedListStack();
        void push(int data) override;
        int pop() override;
        int top() override;
        ~LinkedListStack();
};

#endif
