#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <cstddef>
#include <stdexcept>

template<typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void addFirst(const T&);
    void push_front(const T&);
    void push_back(const T&);
    void insert(int, const T&);
    void remove(int);
    T get(int) const;
    void printList() const;
    void printReverse() const;
    int getSize() const;

    class iterator {
    private:
        typename DoublyLinkedList<T>::Node* current;
    public:
        iterator(typename DoublyLinkedList<T>::Node* ptr) : current(ptr) {}

        T& operator*() {
            return current->value;
        }

        iterator& operator++() {
            current = current->next;
            return *this;
        }

        iterator operator++(int) {
            iterator temp = *this;
            ++(*this);
            return temp;
        }

        iterator& operator--() {
            current = current->prev;
            return *this; 
        }

        iterator operator--(int) {
            iterator temp = *this;
            --(*this);
            return temp;
        }

        bool operator==(const iterator& other) const {
            return current == other.current;
        }

        bool operator!=(const iterator& other) const {
            return current != other.current;
        }
    };

    iterator begin() {
        return iterator(head);
    }

    iterator end() {
        return iterator(nullptr); 
    }

private:
    struct Node {
        T value;
        Node* prev;
        Node* next;
        Node(const T& val) : value(val), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;
};

#include "LinkedList.inl"

#endif // DOUBLY_LINKED_LIST_H
