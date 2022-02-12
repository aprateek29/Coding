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

void printLeftBoundary(Node* root) {

    if (!root) return;
    if (!root->left && !root->right) return;
    cout << root->data << " ";
    if (root->left) {
        printLeftBoundary(root->left);
    } else {
        printLeftBoundary(root->right);
    }

}

void printRightBoundary(Node* root) {

    if (!root) return;
    if (!root->left && !root->right) return;
    if (root->right) {
        printRightBoundary(root->right);
    } else {
        printRightBoundary(root->left);
    }
    cout << root->data << " ";
}

void printLeaves(Node* root) {
    if (!root) return;
    printLeaves(root->left);
    if (!root->left && !root->right) {
        cout << root->data << " ";
    }
    printLeaves(root->right);
}
void solve(Node* root) {
    cout << root->data << " ";
    printLeftBoundary(root->left);
    if (root->left || root->right) {
        printLeaves(root);
    }
    printRightBoundary(root->right);
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