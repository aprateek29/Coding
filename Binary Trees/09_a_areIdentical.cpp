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


bool solve(Node* root1, Node* root2) {
    if (!root1 && !root2) {
        return true;
    }

    if (!root1 || !root2) {
        return false;
    }

    if (root1->data != root2->data) {
        return false;
    }

    return solve(root1->left, root2->left) && solve(root1->right, root2->right);
}


int main() {
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    // root1->right->left = new Node(6);
    root1->right->right = new Node(7);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->right->left = new Node(6);
    root2->right->right = new Node(7);
    cout << solve(root1, root2);
    return 0;
}