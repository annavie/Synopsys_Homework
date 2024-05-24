#include<iostream>

template<typename T>
class Stack {
private:
    struct Node{
        T data;
        Node* next;
    };
    Node* node;
public:
    Stack() : node(nullptr) {}
    ~Stack() {
        while(!isEmpty()){
            pop();
        }
    }
    void push(const T& value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = node;
        node = newNode;
    }
    void pop(){
        if(!isEmpty()) {
            Node* tmp = node;
            node = node->next;
            delete tmp;
        }
    }
    T top() const {
        if(!isEmpty()) {
            return node->data;
        }
        return T{};
    }
    bool isEmpty() const {
        return node == nullptr;
    }
};
int main() {
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    std::cout << "Top element: " << intStack.top() << std::endl;
    while (!intStack.isEmpty()) {
        std::cout << "Popping: " << intStack.top() << std::endl;
        intStack.pop();
    }

    return 0;
}
