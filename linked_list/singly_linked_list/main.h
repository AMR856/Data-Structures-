#include <iostream>

class Node {
private:
    int data;
    Node* next;
public:
    Node(int d, Node* next = nullptr) {
        this->data = d;
        this->next = next;
    }
    ~Node() {}
    int getData() const {
        return data;
    }
    void setData(int d) {
        data = d;
    }
    Node* getNext() const {
        return next;
    }
    void setNext(Node* nextNode) {
        next = nextNode;
    }
};

class LinkedList {
private:
    int size;
    Node* head;
public:
    LinkedList() {
        size = 0;
        head = nullptr;
    }
    int getSize() const {
        return size;
    }
    bool isEmpty() const {
        return size == 0;
    }
    void addNodeLast(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->getNext() != nullptr) {
                current = current->getNext();
            }
            current->setNext(newNode);
        }
        size++;
    }
    void traverse(){
        if (head == nullptr) std::cout << "Linked list is empty" << std::endl;
        Node* current = head;
        while (current != nullptr){
            std::cout << current->getData() << " "; 
            current = current->getNext();
        }
        std::cout << std::endl;
    }
    void addBeginning(int data){
        Node* newNode = new Node(data);
        newNode->setNext(head);
        head = newNode;
    }
    bool search(int data){
        if (head == nullptr) std::cout << "Linked list is empty" << std::endl;
        Node* current = head;
        while (current->getData() != data && current->getNext() != nullptr) current = current->getNext();
        if (current->getData() != data && current->getNext() == nullptr) return false;
        return true;
    }
    void deleteNode(int data) {
        if (head == nullptr) {
            std::cout << "List is empty. Cannot delete.\n";
            return;
        }
        if (head->getData() == data) {
            Node* temp = head;
            head = head->getNext();
            delete temp;
            size--;
            return;
        }
        Node* current = head;
        while (current->getNext() != nullptr && current->getNext()->getData() != data) {
            current = current->getNext();
        }
        if (current->getNext() == nullptr) { 
            std::cout << "Node with data " << data << " not found.\n";
            return;
        }
        Node* temp = current->getNext();
        current->setNext(temp->getNext());
        delete temp;
        size--;
    }
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->getNext();
            delete temp;
        }
    }
};
