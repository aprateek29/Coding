// Key Points
// use map, int distance and level order
// print last element of each vector in map

// Question - Print bottom view of the tree

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


map<int, int> solve(Node* root) {
    map<int, int> m;
    if (!root) return m;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while(!q.empty()) {
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
    return m;
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    map<int, int> m = solve(root);
    for (auto i : m) {
        cout << i.second << " ";
    }
    return 0;
}