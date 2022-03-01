#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

    Node(int d) {
        data = d;
    }
};


void deleteNode(Node* node) {
    node->data = node->next->data;
    Node *temp = node->next;
    node->next = node->next->next;
    delete temp;
}

int main() {

    Node *head1 = new Node(9);
    head1->next = new Node(9);
    head1->next->next = new Node(9);

    deleteNode(head1->next);
    while (head1) {
        cout << head1->data << " ";
        head1 = head1->next;
    }

    return 0;
}