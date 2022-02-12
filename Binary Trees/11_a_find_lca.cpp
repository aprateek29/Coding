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


Node* solve(Node* root, int a, int b) {
    if (!root) return 0;

    if (root->data == a) return root;
    if (root->data == b) return root;

    Node* l = solve(root->left, a, b);
    Node* r = solve(root->right, a, b);

    if (l && r) return root;
    if (l) return l;
    if (r) return r;
    return 0;
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout << solve(root, 2, 4)->data << " ";
    return 0;
}