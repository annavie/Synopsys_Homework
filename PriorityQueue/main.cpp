#include "priority_queue.h"
#include <iostream>

int main() {
    PriorityQueue pq;

    pq.insert(10, 3);
    pq.insert(20, 1);
    pq.insert(15, 2);
    pq.display(); 
    std::cout << "Removed item: " << pq.remove() << std::endl;
    pq.display(); 
    return 0;
}
