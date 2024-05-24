#include "LinkedList.hpp"
#include <list>
int main()
{
    DoublyLinkedList<int> list;
    std::list<int> m;
    m.push_back(1);
    m.begin();
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(0);
    std::cout << "List elements: ";
    for (DoublyLinkedList<int>::iterator it = list.begin(); it != list.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Reverse List elements: ";
    list.printReverse();

    return 0;
}
