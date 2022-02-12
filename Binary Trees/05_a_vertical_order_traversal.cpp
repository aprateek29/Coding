// Key Points
// use a map and and distance variable d = 0 for root
// when going left d = d-1
// when going right d = d+1

// Question - If two nodes have same position the node which comes first in level order
// comes first in output

#include <iostream>
#include <queue>
#include <map>
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


map<int, vector<int>> solve(Node* root) {
    map<int, vector<int>> m; // data, distance
    
    if (!root) {
        return m;
    }

    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        pair<Node*, int> p = q.front();
        q.pop();
        Node* t = p.first;
        int d = p.second;

        m[d].push_back(t->data);

        if (t->left) {
            q.push({t->left, d-1});
        }
        if (t->right) {
            q.push({t->right, d+1});
        }
    }
    return m;
}

void printMap(map<int, vector<int>> m) {
    for (auto i : m) {
        cout << i.first << "-> ";
        for (auto j : i.second) {
            cout << j << " ";
        }
        cout << endl;
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
    map<int, vector<int>> m = solve(root);
    printMap(m);
    return 0;
}