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

Node* solve(Node* head1, Node* head2) {
    Node* dummy = new Node(0);
    Node* t = dummy;
    while (head1 && head2) {
        if (head1->data < head2->data) {
            dummy->next = head1;
            head1 = head1->next;
        } else {
            dummy->next = head2;
            head2 = head2->next;
        }
        dummy = dummy->next;
    }

    if (head1) {
        dummy->next = head1;
    }

    if (head2) {
        dummy->next = head2;
    }
    return t->next;
}

int main() {

    Node* head1 = new Node(10);
    head1->next = new Node(23);
    head1->next->next = new Node(32);
    head1->next->next->next = new Node(34);
    head1->next->next->next->next = new Node(48);

    Node* head2 = new Node(11);
    head2->next = new Node(33);
    head2->next->next = new Node(42);

    Node* head3 = solve(head1, head2);

    while (head3 != NULL) {
        cout << head3->data << " ";
        head3 = head3->next;
    }

    return 0;
}