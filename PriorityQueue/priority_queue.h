#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

class PriorityQueue {
private:
    struct Node {
        int priority;
        int data;
        Node* next;
    };
    Node* head;

public:
    PriorityQueue() : head(nullptr) {}

    void insert(int element, int priority);
    int remove();
    bool isEmpty() const;
    void display() const;

    ~PriorityQueue();
};

#include "priority_queue.inl" 

#endif // PRIORITY_QUEUE_H
