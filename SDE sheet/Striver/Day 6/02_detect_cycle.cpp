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

bool detectCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

int main() {

    Node* head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(2);
    Node* temp = head->next->next;
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = temp;

    cout << detectCycle(head);
    cout << endl;
    int i = 0;
    while (i!=10) {
        i++;
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}