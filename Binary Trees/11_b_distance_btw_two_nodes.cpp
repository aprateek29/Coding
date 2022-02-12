// took a lot of time to find distance between nodes
// https://practice.geeksforgeeks.org/viewSol.php?subId=ce9df3d0802f01f59d746b9dbe605e46&pid=700224&user=aprateek29

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

int dis(Node* root, int a, int b, int d, int &d1, int &d2) {
    if (!root) return 0;

    if (root->data == a) {
        d1 = d;
    }
    if (root->data == b) {
        d2 = d;
    }

    dis(root->left, a, b, d+1, d1, d2);
    dis(root->right, a, b, d+1, d1, d2);
}


Node* solve(Node* root, int a, int b) {
    if (!root) return NULL;

    if (root->data == a) return root;
    if (root->data == b) return root;

    Node* l = solve(root->left, a, b);
    Node* r = solve(root->right, a, b);

    if (l && r) return root;
    if (l) return l;
    if (r) return r;

    return NULL;
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(8);
    root->left->left->left = new Node(6);
    root->left->left->right = new Node(7);

    int a = 8;
    int b = 6;
    int d1 = 0;
    int d2 = 0;
    Node* lca = solve(root, a, b);
    dis(lca, a, b, 0, d1, d2);
    cout << d1 + d2;
    return 0;
}