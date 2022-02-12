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


void solve(Node* root, int k) {

    if (!root) return;
    if (k == 0) {
        cout << root->data << " ";
    }
    solve(root->left, k-1);
    solve(root->right, k-1);
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int k = 2;
    solve(root, k);
    return 0;
}