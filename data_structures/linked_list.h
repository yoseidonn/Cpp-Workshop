#ifndef LINKED_LIST
#define LINKED_LIST

#include "iostream"

using namespace std;

template <typename T>
class Node {
    T value;
    Node* next;
    Node* before;
    
    public: 
        Node(T value): value(value), next(nullptr) {}

    template <typename U>
    friend class LinkedList;
};

template <typename T>
class LinkedList {
    Node<T>* root;
    Node<T>* last;

    public:
        LinkedList(): root(nullptr), last(nullptr) {
            cout << "Linked list initializing." << endl;
        }

        void add(T value) {
            Node<T>* newNode = new Node<T>(value);

            if (this->last == nullptr) {
                this->root = newNode;
            } else {
                this->last->next = newNode;
                newNode->before = this->last;
            }

            this->last = newNode;
        }

        void remove(T value) {
            Node<T>* ptr = this->root;
            while (ptr != nullptr) {
                if (ptr->value == value) {
                    if (ptr->before == nullptr) {
                        this->root = ptr->next;
                    } else if (ptr->next == nullptr) {
                        ptr->before->next = nullptr;
                    } else {
                        ptr->before->next = ptr->next;
                    }
                    break;
                }
                if (ptr->next == nullptr)
                    break;
                else 
                    ptr = ptr->next;
            }
        }

        void display() {
            Node<T>* temp = this->root;

            cout << endl;
            while (temp != nullptr) {
                cout << temp->value << endl;
                temp = temp->next;
            }
            cout << endl;
        }
};

#endif