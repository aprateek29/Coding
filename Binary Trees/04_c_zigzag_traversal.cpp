// Key Points
// From top to bottom
//     from left to right
//     then from right to left
// use two stacks
// push LR in first stack
// push RL in second stack

// Question - Print ZigZag Order Traversal

#include <iostream>
#include <stack>
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


void solve(Node* root) {
    if (!root) {
        return;
    }

    stack<Node*> s1;
    stack<Node*> s2;

    s1.push(root);

    while (!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            Node* t = s1.top();
            s1.pop();
            cout << t->data << " ";

            if (t->left) {
                s2.push(t->left);
            }
            if (t->right) {
                s2.push(t->right);
            }
        }

        while (!s2.empty()) {
            Node* t = s2.top();
            s2.pop();
            cout << t->data << " ";

            if (t->right) {
                s1.push(t->right);
            }
            if (t->left) {
                s1.push(t->left);
            }
        }
    }
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    solve(root);
    return 0;
}