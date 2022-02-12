// Key Points
// swap left and right child
// do preorder

// Question - Invert a binary tree

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


void solve(Node* root) {
    if(!root) return;

    Node* temp = root->right;
    root->right = root->left;
    root->left = temp;

    solve(root->left);
    solve(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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
    inorder(root);
    return 0;
}