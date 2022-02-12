// Key Points
// use a map and and distance variable d = 0 for root
// do preorder
// when going left d = d-1
// when going right d = d+1

// Question - If two nodes have same position the node which comes first in preorder
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

void solve(Node* root, int d, map<int, vector<int>> &m) {
    if (!root) return;

    m[d].push_back(root->data);

    solve(root->left, d-1, m);
    solve(root->right, d, m);
}

void printMap(map<int, vector<int>> &m) {
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
    map<int, vector<int>> m;
    solve(root, 0, m);
    printMap(m);
    return 0;
}