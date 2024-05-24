
struct Node {
        int data;
        struct Node* next;
    }
bool has_cycle(Node* head) {

    Node* fast = head;
    Node* slow = head;
    while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        if(fast == slow) {
            return true;
        }
        
    }
    return false;
    }