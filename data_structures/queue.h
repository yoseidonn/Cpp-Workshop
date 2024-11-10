#ifndef QUEUE
#define QUEUE

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
class Queue {
private:
    Node<T>* front;
    Node<T>* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {
        cout << "Queue initializing." << endl;
    }

    void enqueue(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (this->rear != nullptr) {
            this->rear->next = newNode;
        }
        this->rear = newNode;
        if (this->front == nullptr) {
            this->front = newNode;
        }
    }

    void dequeue() {
        if (this->front != nullptr) {
            Node<T>* temp = this->front;
            this->front = this->front->next;
            if (this->front == nullptr) {
                this->rear = nullptr;
            }
            delete temp;
        }
    }

    void display() {
        Node<T>* temp = this->front;
        cout << endl;
        while (temp != nullptr) {
            cout << temp->value << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};

#endif
