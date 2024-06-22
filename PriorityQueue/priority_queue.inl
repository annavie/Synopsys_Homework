#include <iostream>
#include "priority_queue.h"

void PriorityQueue::insert(int element, int priority) {
    Node* newNode = new Node;
    newNode->data = element;
    newNode->priority = priority;
    newNode->next = nullptr;

    if (head == nullptr || priority < head->priority) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* curr = head;
        while (curr->next != nullptr && curr->next->priority <= priority) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

int PriorityQueue::remove() {
    if (isEmpty()) {
        return -1; 
    }
    Node* tmp = head;
    int element = head->data;
    head = head->next;
    delete tmp;
    return element;
}

bool PriorityQueue::isEmpty() const {
    return (head == nullptr);
}

void PriorityQueue::display() const {
    if (isEmpty()) {
        std::cout << "Priority Queue is empty." << std::endl;
    } else {
        Node* current = head;
        std::cout << "Priority Queue:" << std::endl;
        while (current != nullptr) {
            std::cout << "(" << current->data << ", " << current->priority << ")" << std::endl;
            current = current->next;
        }
    }
}

PriorityQueue::~PriorityQueue() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
