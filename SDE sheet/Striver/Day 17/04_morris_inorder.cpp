#include <iostream>
#include <stack>
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


void solve(Node* root) {
    Node* curr = root;
    while (curr) {
        if (!curr->left) {
            cout << curr->data << " ";
            curr = curr->right;
        } else {
            Node* p = curr->left;
            while (p->right && p->right != curr) {
                p = p->right;
            }
            if (p->right == curr) {
                p->right = NULL;
                curr = curr->right;
            } else {
                p->right = curr;
                cout << curr->data << " "; 
                curr = curr->left;
            }
        }
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