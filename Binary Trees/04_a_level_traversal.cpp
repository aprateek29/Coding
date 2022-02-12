// Key Points
// use a queue
// pop queue
// push left child
// push right child
// 
// Don't forget to pop from the queue

// Question - Print Level Order Traversal left to right

#include <iostream>
#include <queue>
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
    if (!root) {
        return;
    }

    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* t = q.front();
        cout << t->data << " ";
        q.pop();
        if (t->left) {
            q.push(t->left);
        }

        if (t->right) {
            q.push(t->right);
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