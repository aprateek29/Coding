// Key Points
// Use level order
// Use isFirst and push Null into queue

// Question - print left view of a tree

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
    if (!root) return;
    queue<Node*> q;
    bool isFirst = true;

    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* t = q.front();
        q.pop();
        if (!t) {
            isFirst = true;
            if (q.size() != 0) {
                q.push(NULL);
            }
        } else {
            if (isFirst) {
                cout << t->data << " ";
                isFirst = false;
            }

            if (t->left) {
                q.push(t->left);
            }
            if (t->right) {
                q.push(t->right);
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