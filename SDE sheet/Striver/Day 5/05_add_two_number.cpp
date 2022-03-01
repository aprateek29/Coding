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

Node* solve(Node* l1, Node* l2) {
    Node* dummy = new Node(0);
    Node* t = dummy;
    int carry = 0;
    while (l1 && l2) {
        int temp = l1->data + l2->data + carry;
        carry = temp / 10;
        dummy->next = new Node(temp%10);
        dummy = dummy->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    
    while (l1) {
        int temp = l1->data + carry;
        carry = temp / 10;
        dummy->next = new Node(temp%10);
        dummy = dummy->next;
        l1 = l1->next;
    }
    
    while (l2) {
        int temp = l2->data + carry;
        carry = temp / 10;
        dummy->next = new Node(temp%10);
        dummy = dummy->next;
        l2 = l2->next;
    }
    
    if (carry) {
        dummy->next = new Node(1);
    }
    
    return t->next;
}

int main() {

    Node* head1 = new Node(9);
    head1->next = new Node(9);
    head1->next->next = new Node(9);

    Node* head2 = new Node(1);

    Node* head3 = solve(head1, head2);

    while (head3) {
        cout << head3->data << " ";
        head3 = head3->next;
    }

    return 0;
}