// Key Points
// Value of node = sum of left subtree + sum of right subtree
// use a bool flag variable

// Question - Check binary tree is sumTree;

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


int solve(Node* root) {
    if (!root) return 0;

    if (!root->left && !root->right) {
        return root->data;
    }

    int l = solve(root->left);
    int r = solve(root->right);

    if (root->data != l+r) {
        cout << "Not sum tree" << endl;
    } else {
        cout << "Sum tree" << endl;
    }

    return root->data + l + r;
}


int main() {
    Node* root = new Node(22);
    root->left = new Node(6);
    root->right = new Node(5);
    root->left->left = new Node(4);
    root->left->right = new Node(2);
    root->right->left = new Node(1);
    root->right->right = new Node(4);
    solve(root);
    return 0;
}