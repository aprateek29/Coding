// Question - Convert binary tree leaves to doubly linked list

#include <iostream>
using namespace std;


class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};


Node* solve(Node* root, Node* &head, Node* &tail) {
    if (!root) return NULL;

    if (!root->left && !root->right) {
        if (!head) {
            head = root;
        } else {
            root->left = tail;
            tail->right = root;
        }
        tail = root;
        return NULL;
    } 
    root->left = solve(root->left, head, tail);
    root->right = solve(root->right, head, tail);
    return root;
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(5);
    root->left->right = new Node(6);
    root->right->left = new Node(4);
    Node* head = NULL;
    Node* tail = NULL;
    solve(root, head, tail);
    while (head) {
        cout << head->data << " ";
        head = head->right;
    }
    return 0;
}