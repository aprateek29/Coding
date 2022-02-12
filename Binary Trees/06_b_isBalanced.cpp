// Key Points
// In balanced tree max diff of height between any leaf nodes is less than 2

// Question - Check if tree is balanced

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


int solve(Node* root, bool &flag) {
    if (!root) return 0;

    int l = solve(root->left, flag);
    int r = solve(root->right, flag);

    if (abs(l-r) > 1) {
        flag = false;
    }

    return 1 + max(l, r);
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    bool flag = true;
    solve(root, flag);
    cout << flag << endl;
    return 0;
}