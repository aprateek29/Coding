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
    if (!root) return 0;

    int lh = solve(root->left, d);
    int rh = solve(root->right, d);

    if (d < 1 + lh + rh) {
        d = 1 + lh + rh;
    }
    return 1 + max(lh, rh);
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int d = 0;
    solve(root, d);
    cout << d; 
    return 0;
}