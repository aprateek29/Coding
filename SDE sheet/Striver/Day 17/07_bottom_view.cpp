#include <iostream>
#include <map>
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
    map<int, int> m;

    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        pair<Node*, int> p = q.front();
        q.pop();

        Node* t = p.first;
        int d = p.second;

        m[d] = t->data;

        if (t->left) {
            q.push({t->left, d-1});
        }

        if (t->right) {
            q.push({t->right, d+1});
        }

    }

    for (auto i : m) {
        cout << i.second << " ";
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