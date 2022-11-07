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

    Node* temp1 = head1;
    Node* temp2 = head2;

    while (temp1 != temp2) {

        if (!temp1) {
            temp1 = head2;
        }

        if (!temp2) {
            temp2 = head1;
        }

        temp2 = temp2->next;
        temp1 = temp1->next;
    }

    return temp1;
}

int main() {

    Node* head1 = new Node(3);
    head1->next = new Node(5);
    head1->next->next = new Node(7);
    head1->next->next->next = new Node(11);

    Node* head2 = new Node(34);
    head2->next = new Node(3);
    head2->next->next = new Node(54);
    head2->next->next->next = head1->next->next;

    cout << solve(head1, head2)->data << endl;

    while (head1) {
        cout << head1->data << " ";
        head1 = head1->next;
    }
    cout << endl;
    while (head2) {
        cout << head2->data << " ";
        head2 = head2->next;
    }

    return 0;
}