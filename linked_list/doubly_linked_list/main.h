#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <math.h>

class DoublyLinkedListNode {
private:
    int data;
    DoublyLinkedListNode *next;
    DoublyLinkedListNode *prev;
public:
DoublyLinkedListNode(int data) : data(data), next(nullptr), prev(nullptr){}
    DoublyLinkedListNode(int data,
    DoublyLinkedListNode *next) : data(data), next(next),  prev(nullptr){}
    DoublyLinkedListNode(int data,
    DoublyLinkedListNode *next,
    DoublyLinkedListNode *prev) : data(data), next(next), prev(prev) {}
    void setNext(DoublyLinkedListNode* nextNode) {next = nextNode;}
    DoublyLinkedListNode* getNext() const {return next;}
    void setPrev(DoublyLinkedListNode *prevNode){prev = prevNode;}
    DoublyLinkedListNode* getPrev() const {return prev;}
    int getData() const {return data;}
    void setData(int d) {data = d;}
};  

class AbstractLinkedList {
protected:
    int size;
public:
    int getSize() const {return size;}
    bool isEmpty() const {return size == 0;}
    virtual void addNodeLast(int data) = 0;
    virtual void traverse() = 0;
    virtual void addBeginning(int data) = 0;
    virtual bool search(int data) = 0;
    virtual void deleteNode(int data) = 0;
    virtual void deleteEnd() = 0;
    virtual void deleteFirst() = 0;
    virtual ~AbstractLinkedList() {}
};


class DoublyLinkedList : public AbstractLinkedList {
private:
    DoublyLinkedListNode *head;
    DoublyLinkedListNode *tail;
public:
    void addNodeLast(int data) override;
    void traverse() override;
    void traverseBackward();
    void addBeginning(int data);
    bool search(int data);
    void deleteNode(int data);
    void deleteEnd();
    void deleteFirst();
    ~DoublyLinkedList();
};

#endif