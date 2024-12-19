#ifndef MAIN_H
#define MAIN_H

#include <iostream>

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
    virtual ~AbstractLinkedList() {}
};

class SinglyLinkedList : public AbstractLinkedList {
private:
    SinglyLinkedListNode *head;
public:
    void addNodeLast(int data) override;
    void traverse() override;
    void addBeginning(int data);
    bool search(int data);
    void deleteNode(int data);
    ~SinglyLinkedList();
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
    ~DoublyLinkedList();
};

#endif 
