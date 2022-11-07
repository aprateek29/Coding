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
    if (!root->left && !root->right) return root->data;

    int l = solve(root->left);
    int r = solve(root->right);
    root->data = l + r;
    return root->data;
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " "; 
        inorder(root->right);
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

    inorder(root);
    return 0;
}