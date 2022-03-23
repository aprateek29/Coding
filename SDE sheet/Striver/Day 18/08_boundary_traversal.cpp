// gfg

#include <iostream>
#include <vector>
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

void leftBoundary(Node* root, vector<int> &v) {
    if (!root) return;
    if (!root->left && !root->right) return;

    v.push_back(root->data);
    if (root->left) {
        leftBoundary(root->left, v);
    } else {
        leftBoundary(root->right, v);
    }

}

void rightBoundary(Node *root, vector<int> &v) {
    if (!root) return;
    if (!root->left && !root->right) return;

    if (root->right) {
        leftBoundary(root->right, v);
    } else {
        leftBoundary(root->left, v);
    }
    v.push_back(root->data);
}

void leaves(Node *root, vector<int> &v) {
    if (!root) return;

    if (!root->left && !root->right) {
        v.push_back(root->data);
    }

    leaves(root->left, v);
    leaves(root->right, v);
}

void solve(Node* root) {
    vector<int> v;
    v.push_back(root->data);
    leftBoundary(root->left, v);
    if (root->left && root->right) {
        leaves(root, v);
    }
    rightBoundary(root->right, v);

    for (auto i : v) {
        cout << i << " ";
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
    return 0;
}