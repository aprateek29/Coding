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


int solve(Node* root, int &d) {
    if (!root) {
        return 0;
    }

    if (!root->left && !root->right) {
        return root->data;
    }

    int ls = solve(root->left, d);
    int rs = solve(root->right, d);

    if (root->data + ls + rs > d) {
        d = root->data + ls + rs;
    }

    return max(root->data + max(ls, rs), root->data);
}


int main() {
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);
    int d = 0;
    solve(root, d);
    cout << d;
    return 0;
}