#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next = NULL;
    
        Node(int d) {
            data = d;
        }
};

Node* reverse(Node* head) {
    if (!head || !head->next) {
        return head;
    }

    Node* newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head = reverse(head);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }


    return 0;
}