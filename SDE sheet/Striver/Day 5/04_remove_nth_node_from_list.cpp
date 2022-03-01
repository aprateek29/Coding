#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int d) {
            data = d;
            next = NULL;
        }
};

void removeNode(Node* head, int x) {
    Node* slow = head;
    Node* fast = head;
    Node* prev;
    int i = 0;
    while (i != x) {
        fast = fast->next;
        i++;
    }
    while (fast) {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }
    prev->next = prev->next->next;
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    removeNode(head, 2);

    while (head) {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}