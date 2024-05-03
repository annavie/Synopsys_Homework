#ifndef DOUBLY_LINKED_LIST_INL_H
#define DOUBLY_LINKED_LIST_INL_H

#include <stdexcept>
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

template<typename T>
void DoublyLinkedList<T>::addFirst(const T& value) {
    Node* temp = new Node{value, nullptr, head};
    if (head != nullptr) {
        head->prev = temp;
    } else {
        tail = temp; 
    }
    head = temp;
    size++;
}

template<typename T>
void DoublyLinkedList<T>::push_front(const T& value) {
    if (head == nullptr) {
        head = tail = new Node(value);
    } else {
        Node* temp = new Node(value);
        temp->prev = nullptr;
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    size++;
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
    if (head == nullptr) {
        head = tail = new Node(value);
    } else {
        Node* temp = new Node(value);
        temp->prev = tail;
        temp->next = nullptr;
        tail->next = temp;
        tail = temp;
    }
    size++;
}

template<typename T>
void DoublyLinkedList<T>::insert(int index, const T& value) {
    if (index < 0 || index > size) {
        throw std::out_of_range("Index out of range.");
    }
    if (index == 0) {
        addFirst(value);
    } else if (index == size) {
        push_back(value);
    } else {
        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node* temp = new Node{value, current, current->next};
        current->next->prev = temp;
        current->next = temp;
        size++;
    }
}

template<typename T>
void DoublyLinkedList<T>::remove(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range.");
    }
    if (index == 0) {
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    } else if (index == size - 1) {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    } else {
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }
    size--;
}

template<typename T>
T DoublyLinkedList<T>::get(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range.");
    }
    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->value;
}

template<typename T>
void DoublyLinkedList<T>::printList() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template<typename T>
void DoublyLinkedList<T>::printReverse() const {
    Node* current = tail;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

template<typename T>
int DoublyLinkedList<T>::getSize() const {
    return size;
}

#endif // DOUBLY_LINKED_LIST_INL_H
