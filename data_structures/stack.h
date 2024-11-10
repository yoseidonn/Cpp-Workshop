#ifndef STACK
#define STACK

#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
    T value;
    Node* next;

    Node(T value) : value(value), next(nullptr) {}
};

template <typename T>
class Stack {
private:
    Node<T>* top;

public:
    Stack() : top(nullptr) {
        cout << "Stack initializing." << endl;
    }

    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = this->top;
        this->top = newNode;
    }

    void pop() {
        if (this->top != nullptr) {
            Node<T>* temp = this->top;
            this->top = this->top->next;
            delete temp;
        }
    }

    void display() {
        Node<T>* temp = this->top;
        cout << endl;
        while (temp != nullptr) {
            cout << temp->value << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};

#endif
